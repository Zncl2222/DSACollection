import numpy as np
import matplotlib.pyplot as plt
from matplotlib.colors import ListedColormap


class SVM:
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
    svm = SVM(learning_rate=0.01, n_iterations=3000)
    svm.fit(X_train, y_train)

    # Predict
    predictions = svm.predict(X_test)

    def accuracy(y_true, y_pred):
        accuracy = np.sum(y_true == y_pred) / len(y_true)
        return accuracy

    print("Accuracy:", accuracy(y_test, predictions))

    # Plot decision boundary for custom SVM
    svm.plot_decision_boundary(X_train, y_train, title='Custom SVM Decision Boundary')
    svm.plot_decision_boundary(X_test, y_test, title='Custom SVM Decision Boundary')
