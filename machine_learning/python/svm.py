import numpy as np
import matplotlib.pyplot as plt
from matplotlib.colors import ListedColormap


class SVM:
    def __init__(self, kernel='linear', C=1.0, gamma=None):
        self.kernel = kernel
        self.C = C
        self.gamma = gamma
        self.alpha = None
        self.b = None
        self.X = None
        self.support_vector_label = None

    def _kernel(self, X, y):
        if self.kernel == 'linear':
            return np.dot(self.y, self.y.T)
        if self.kernel == 'polynomial':
            return (1 + np.dot(self.y, self.y.T)) ** self.gamma
        if self.kernel == 'rbf':
            return np.exp(-self.gamma * np.linalg.norm(X - y) ** 2)

    def fit(self, X: np.array, y: np.array):
        n_sample, n_feature = X.shape
        kernel_matrix = np.zeros((n_sample, n_sample))
        for i in range(n_sample):
            for j in range(n_sample):
                kernel_matrix[i, j] = self._kernel(X[i], X[j])

        # P = np.outer(y, y) * kernel_matrix
        # q = -np.ones(n_sample)
        # G = -np.eye(n_sample)
        # h = np.zeros(n_sample)
        # A = y.reshape(1, -1)
        # b = 0.0
        # tolerance = 1e-6
        # print(q)
        # print(n_sample)
        # print(np.dot(G, q).shape)
        # lagrange_a = np.linalg.solve(np.dot(G, P) + np.eye(n_sample), np.ones(G, q))
        # alpha = np.zeros(n_sample)
        Q = np.outer(y, y) * kernel_matrix
        b = np.ones(n_sample)
        alpha = np.linalg.solve(Q + np.eye(n_sample), b)
        alpha = np.minimum(alpha, self.C)
        tolerance = 1e-6

        # Identify support vectors
        sv = alpha > tolerance
        self.support_vectors = X[sv]
        self.alpha_sv = alpha[sv]
        self.y_sv = y[sv]

        # sv = lagrange_a > tolerance
        index = np.arange(len(alpha))[sv]
        # self.alpha = lagrange_a[sv]
        # self.support_vector = X[sv]
        # self.support_vector_ans = y[sv]

        self.b = 0
        for n in range(len(self.alpha_sv)):
            self.b += self.y_sv[n]
            self.b -= np.sum(self.alpha_sv * self.y_sv * kernel_matrix[index[n], sv])
        self.b /= len(self.alpha_sv)

        self.w = np.zeros(n_feature)
        for n in range(len(self.alpha_sv)):
            self.w += self.alpha_sv[n] * self.y_sv[n] * self.support_vectors[n]

    def predict(self, X: np.array):
        if self.kernel == 'linear':
            return np.sign(np.dot(X, self.w) + self.b)
        else:
            n_sample = X.shape[0]
            y_predict = np.zeros(n_sample)
            for i in range(n_sample):
                s = 0
                for a, sv_y, sv in zip(self.alpha_sv, self.y_sv, self.support_vectors):
                    s += a * sv_y * self._kernel(X[i], sv)
                y_predict[i] = s
            return np.sign(y_predict + self.b)

    def plot_decision_boundary(
        self, X: np.array, y: np.array, title: str = 'SVM Decision Boundary'
    ) -> None:
        h = 0.05  # step size in the mesh

        # Create color maps
        cmap_light = ListedColormap(['#FFAAAA', '#AAFFAA'])
        cmap_bold = ListedColormap(['#FF0000', '#00FF00'])

        # Plot the decision boundary
        x_min, x_max = X[:, 0].min() - 1, X[:, 0].max() + 1
        y_min, y_max = X[:, 1].min() - 1, X[:, 1].max() + 1
        xx, yy = np.meshgrid(np.arange(x_min, x_max, h), np.arange(y_min, y_max, h))
        Z = self.predict(np.c_[xx.ravel(), yy.ravel()])

        # Put the result into a color plot
        Z = Z.reshape(xx.shape)
        figure = plt.figure()
        plt.pcolormesh(xx, yy, Z, cmap=cmap_light)

        # Plot the training points
        plt.scatter(X[:, 0], X[:, 1], c=y, cmap=cmap_bold, edgecolor='k', s=20)
        plt.xlim(xx.min(), xx.max())
        plt.ylim(yy.min(), yy.max())
        plt.title(title)

        plt.show()
        figure.savefig('test.png', dpi=300)


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
        self, X: np.array, y: np.array, title: str = 'SVM Decision Boundary'
    ) -> None:
        h = 0.02  # step size in the mesh

        # Create color maps
        cmap_light = ListedColormap(['#FFAAAA', '#AAFFAA'])
        cmap_bold = ListedColormap(['#FF0000', '#00FF00'])

        # Plot the decision boundary
        x_min, x_max = X[:, 0].min() - 1, X[:, 0].max() + 1
        y_min, y_max = X[:, 1].min() - 1, X[:, 1].max() + 1
        xx, yy = np.meshgrid(np.arange(x_min, x_max, h), np.arange(y_min, y_max, h))
        Z = self.predict(np.c_[xx.ravel(), yy.ravel()])

        # Put the result into a color plot
        Z = Z.reshape(xx.shape)
        figure = plt.figure()
        plt.pcolormesh(xx, yy, Z, cmap=cmap_light)

        # Plot the training points
        plt.scatter(X[:, 0], X[:, 1], c=y, cmap=cmap_bold, edgecolor='k', s=20)
        plt.xlim(xx.min(), xx.max())
        plt.ylim(yy.min(), yy.max())
        plt.title(title)

        plt.show()
        figure.savefig('test.png', dpi=300)


if __name__ == "__main__":
    from sklearn.datasets import make_blobs
    from sklearn.model_selection import train_test_split
    from sklearn.preprocessing import StandardScaler

    X, y = make_blobs(n_samples=400, centers=2, random_state=0, cluster_std=0.6)
    y = np.where(y == 0, -1, 1)

    # Split data into training and testing sets
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

    # Standardize features
    scaler = StandardScaler()
    X_train = scaler.fit_transform(X_train)
    X_test = scaler.transform(X_test)

    # Instantiate and train SVM classifier
    # svm = SVMGD(learning_rate=0.01, n_iterations=3000)
    svm = SVM(kernel='rbf', gamma=0.5, C=10)
    svm.fit(X_train, y_train)

    # Predict
    predictions = svm.predict(X_test)

    def accuracy(y_true, y_pred):
        accuracy = np.sum(y_true == y_pred) / len(y_true)
        return accuracy

    print("Accuracy:", accuracy(y_test, predictions))

    # Plot decision boundary for custom SVM
    # svm.plot_decision_boundary(X_train, y_train, title='Custom SVM Decision Boundary')
    svm.plot_decision_boundary(X_test, y_test, title='Custom SVM Decision Boundary')
