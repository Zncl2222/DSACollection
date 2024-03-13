import numpy as np

from machine_learning.python.svm import SVM

from sklearn.datasets import make_blobs
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler


def test_svm():
    X, y = make_blobs(n_samples=400, centers=2, random_state=0, cluster_std=0.6)
    y = np.where(y == 0, -1, 1)

    # Split data into training and testing sets
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

    # Standardize features
    scaler = StandardScaler()
    X_train = scaler.fit_transform(X_train)
    X_test = scaler.transform(X_test)

    # Instantiate and train SVM classifier
    svm = SVM(learning_rate=0.1, lambda_param=0.01, n_iterations=3000)
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
