import numpy as np
from cvxopt import matrix, solvers
import matplotlib.pyplot as plt
from matplotlib.colors import ListedColormap
from sklearn.svm import SVC


class SVM:
    def __init__(self, kernel='linear', C=1.0, gamma=0.1):
        self.kernel = kernel
        self.C = C
        self.sv = None
        self.sv_y = None
        self.alpha = None
        self.gamma = gamma
        self.b = 0

    def _kernel(self, x1: np.ndarray, x2: np.ndarray) -> np.ndarray:
        if self.kernel == 'linear':
            return np.dot(x1, x2)
        elif self.kernel == 'rbf':
            return np.exp(-self.gamma * np.linalg.norm(x1 - x2) ** 2)
        else:
            raise ValueError('kernel not supported')

    def _compute_gram_matrix(self, X: np.ndarray, n_samples: int):
        K = np.zeros((n_samples, n_samples))
        for i in range(n_samples):
            for j in range(n_samples):
                K[i, j] = self._kernel(X[i], X[j])
        return K

    def fit(self, X: np.array, y: np.array):
        n_samples = X.shape[0]

        # Gram matrix
        K = self._compute_gram_matrix(X, n_samples)

        P = matrix(np.outer(y, y) * K)
        q = matrix(-np.ones(n_samples))
        G = matrix(np.vstack((np.eye(n_samples) * -1, np.eye(n_samples))))
        h = matrix(np.hstack((np.zeros(n_samples), np.ones(n_samples) * self.C)))
        A = matrix(y, (1, n_samples), 'd')
        b = matrix(0.0)

        sol = solvers.qp(P, q, G, h, A, b)
        a = np.ravel(sol['x'])

        # Support vectors have non zero lagrange multipliers
        sv = a > 1e-5
        sv_indices = np.arange(len(a))[sv]
        self.sv = X[sv]
        self.sv_y = y[sv]
        self.alpha = a[sv]

        for n in range(len(self.alpha)):
            self.b += self.sv_y[n]
            self.b -= np.sum(self.alpha * self.sv_y * K[sv_indices[n], sv])
        self.b /= len(self.alpha)

        # Compute w
        if self.kernel == 'linear':
            self.w = np.dot((self.alpha * self.sv_y), self.sv)

    def project(self, X: np.ndarray) -> float:
        if self.kernel == 'linear':
            return np.dot(X, self.w) + self.b
        else:
            y_predict = np.zeros(len(X))
            for i in range(len(X)):
                s = 0
                for a, sv_y, sv in zip(self.alpha, self.sv_y, self.sv):
                    s += a * sv_y * self._kernel(X[i], sv)
                y_predict[i] = s
            return y_predict + self.b

    def predict(self, X: np.ndarray) -> np.ndarray:
        return np.sign(self.project(X))


class SVMGD:
    """
    The Support Vector Machine that use Gradient Descent to solve the optimization problem.
    This implementation only support linear SVM.
    """

    def __init__(
        self, learning_rate: float = 0.001, lambda_param: float = 0.01, n_iterations: int = 1000
    ):
        self.lr = learning_rate
        self.lambda_param = lambda_param
        self.n_iterations = n_iterations
        self.w = None
        self.b = None

    def fit(self, X: np.array, y: np.array) -> None:
        _, n_features = X.shape

        _y = np.where(y <= 0, -1, 1)

        self.w = np.random.normal(loc=0, scale=1.0, size=n_features)
        self.b = np.random.normal(loc=0, scale=1.0)

        for _ in range(self.n_iterations):
            for idx, x in enumerate(X):
                condition = _y[idx] * (np.dot(x, self.w) - self.b) >= 1
                if condition:
                    self.w -= self.lr * (2 * self.lambda_param * self.w)
                else:
                    self.w -= self.lr * (2 * self.lambda_param * self.w - np.dot(x, _y[idx]))

    def predict(self, X: np.array) -> np.array:
        approximation = np.dot(X, self.w) - self.b
        return np.sign(approximation)


def plot_decision_boundary(
    X: np.array, y: np.array, classifier, title: str = 'SVM Decision Boundary'
) -> None:
    h = 0.1  # step size in the mesh

    # Create color maps
    cmap_light = ListedColormap(['#FFAAAA', '#AAFFAA'])
    cmap_bold = ListedColormap(['#FF0000', '#00FF00'])

    # Plot the decision boundary
    x_min, x_max = X[:, 0].min() - 1, X[:, 0].max() + 1
    y_min, y_max = X[:, 1].min() - 1, X[:, 1].max() + 1
    xx, yy = np.meshgrid(np.arange(x_min, x_max, h), np.arange(y_min, y_max, h))
    Z = classifier.predict(np.c_[xx.ravel(), yy.ravel()])

    # Put the result into a color plot
    Z = Z.reshape(xx.shape)
    plt.pcolormesh(xx, yy, Z, cmap=cmap_light)

    # Plot the training points
    plt.scatter(X[:, 0], X[:, 1], c=y, cmap=cmap_bold, edgecolor='k', s=20)
    plt.xlim(xx.min(), xx.max())
    plt.ylim(yy.min(), yy.max())
    plt.title(title)


if __name__ == "__main__":
    from sklearn.datasets import make_blobs
    from sklearn.model_selection import train_test_split
    from sklearn.preprocessing import StandardScaler

    X, y = make_blobs(n_samples=400, random_state=0)
    y = np.where(y == 0, -1, 1)

    # Split data into training and testing sets
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

    def accuracy(y_true, y_pred):
        accuracy = np.sum(y_true == y_pred) / len(y_true)
        return accuracy

    # Standardize features
    scaler = StandardScaler()
    X_train = scaler.fit_transform(X_train)
    X_test = scaler.transform(X_test)

    # Instantiate and train SVM classifier
    svm = SVM(kernel='rbf', gamma=0.5, C=0.5)
    svm.fit(X_train, y_train)

    svc = SVC(kernel='rbf', gamma=0.5, C=0.5)
    svc.fit(X_train, y_train)

    svmgd = SVMGD(learning_rate=0.01, n_iterations=3000)
    svmgd.fit(X_train, y_train)

    # Predict
    predictions_svc = svc.predict(X_test)
    print("Accuracy (svc):", accuracy(y_test, predictions_svc))

    # Predict
    predictions_svm = svm.predict(X_test)
    print("Accuracy (svm):", accuracy(y_test, predictions_svm))

    # Predict
    predictions_svmgd = svmgd.predict(X_test)
    print("Accuracy (svmgd):", accuracy(y_test, predictions_svmgd))

    plt.figure(1)
    plot_decision_boundary(X_test, y_test, svc, title='SVM Decision Boundary')

    plt.figure(2)
    plot_decision_boundary(X_test, y_test, svm, title='Custom SVM Decision Boundary')

    plt.figure(3)
    plot_decision_boundary(X_test, y_test, svmgd, title='Custom SVM Decision Boundary')
    plt.show()
