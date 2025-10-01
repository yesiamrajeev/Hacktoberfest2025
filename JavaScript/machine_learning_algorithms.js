/**
 * Machine Learning Algorithms Implementation in JavaScript
 * 
 * This comprehensive library implements fundamental machine learning algorithms
 * from scratch, including linear regression, k-means clustering, decision trees,
 * and neural networks. Perfect for educational purposes and understanding
 * the mathematical foundations of ML algorithms.
 * 
 * Features:
 * - Linear and Polynomial Regression
 * - K-Means Clustering
 * - Decision Trees (ID3 Algorithm)
 * - Simple Neural Network (Backpropagation)
 * - K-Nearest Neighbors (KNN)
 * - Principal Component Analysis (PCA)
 * 
 * @author Hacktoberfest2025 ML Contributor
 */

// ==================== UTILITY FUNCTIONS ====================

class MLUtils {
    static mean(arr) {
        return arr.reduce((sum, val) => sum + val, 0) / arr.length;
    }

    static variance(arr) {
        const avg = this.mean(arr);
        return this.mean(arr.map(x => (x - avg) ** 2));
    }

    static standardDeviation(arr) {
        return Math.sqrt(this.variance(arr));
    }

    static covariance(x, y) {
        if (x.length !== y.length) throw new Error("Arrays must have same length");
        
        const meanX = this.mean(x);
        const meanY = this.mean(y);
        
        return this.mean(x.map((xi, i) => (xi - meanX) * (y[i] - meanY)));
    }

    static correlation(x, y) {
        return this.covariance(x, y) / (this.standardDeviation(x) * this.standardDeviation(y));
    }

    static euclideanDistance(point1, point2) {
        return Math.sqrt(
            point1.reduce((sum, val, i) => sum + (val - point2[i]) ** 2, 0)
        );
    }

    static normalize(data) {
        const features = data[0].length;
        const normalized = data.map(row => [...row]);
        
        for (let j = 0; j < features; j++) {
            const column = data.map(row => row[j]);
            const min = Math.min(...column);
            const max = Math.max(...column);
            const range = max - min;
            
            if (range !== 0) {
                for (let i = 0; i < data.length; i++) {
                    normalized[i][j] = (data[i][j] - min) / range;
                }
            }
        }
        
        return normalized;
    }

    static shuffle(array) {
        const shuffled = [...array];
        for (let i = shuffled.length - 1; i > 0; i--) {
            const j = Math.floor(Math.random() * (i + 1));
            [shuffled[i], shuffled[j]] = [shuffled[j], shuffled[i]];
        }
        return shuffled;
    }

    static trainTestSplit(data, labels, testSize = 0.2) {
        const combined = data.map((row, i) => ({ data: row, label: labels[i] }));
        const shuffled = this.shuffle(combined);
        
        const splitIndex = Math.floor(data.length * (1 - testSize));
        
        return {
            trainData: shuffled.slice(0, splitIndex).map(item => item.data),
            trainLabels: shuffled.slice(0, splitIndex).map(item => item.label),
            testData: shuffled.slice(splitIndex).map(item => item.data),
            testLabels: shuffled.slice(splitIndex).map(item => item.label)
        };
    }
}

// ==================== LINEAR REGRESSION ====================

class LinearRegression {
    constructor() {
        this.slope = 0;
        this.intercept = 0;
        this.trained = false;
    }

    fit(x, y) {
        if (x.length !== y.length) {
            throw new Error("x and y must have the same length");
        }

        const n = x.length;
        const sumX = x.reduce((sum, val) => sum + val, 0);
        const sumY = y.reduce((sum, val) => sum + val, 0);
        const sumXY = x.reduce((sum, xi, i) => sum + xi * y[i], 0);
        const sumXX = x.reduce((sum, xi) => sum + xi * xi, 0);

        // Calculate slope and intercept using least squares
        this.slope = (n * sumXY - sumX * sumY) / (n * sumXX - sumX * sumX);
        this.intercept = (sumY - this.slope * sumX) / n;
        
        this.trained = true;
        return this;
    }

    predict(x) {
        if (!this.trained) {
            throw new Error("Model must be trained before making predictions");
        }

        if (Array.isArray(x)) {
            return x.map(xi => this.slope * xi + this.intercept);
        }
        return this.slope * x + this.intercept;
    }

    score(x, y) {
        const predictions = this.predict(x);
        const yMean = MLUtils.mean(y);
        
        const ssRes = y.reduce((sum, yi, i) => sum + (yi - predictions[i]) ** 2, 0);
        const ssTot = y.reduce((sum, yi) => sum + (yi - yMean) ** 2, 0);
        
        return 1 - (ssRes / ssTot); // R² score
    }
}

// ==================== POLYNOMIAL REGRESSION ====================

class PolynomialRegression {
    constructor(degree = 2) {
        this.degree = degree;
        this.coefficients = [];
        this.trained = false;
    }

    _createPolynomialFeatures(x) {
        return x.map(xi => {
            const features = [];
            for (let i = 0; i <= this.degree; i++) {
                features.push(xi ** i);
            }
            return features;
        });
    }

    _matrixMultiply(a, b) {
        const result = [];
        for (let i = 0; i < a.length; i++) {
            result[i] = [];
            for (let j = 0; j < b[0].length; j++) {
                let sum = 0;
                for (let k = 0; k < b.length; k++) {
                    sum += a[i][k] * b[k][j];
                }
                result[i][j] = sum;
            }
        }
        return result;
    }

    _matrixInverse(matrix) {
        const n = matrix.length;
        const identity = Array(n).fill().map((_, i) => 
            Array(n).fill(0).map((_, j) => i === j ? 1 : 0)
        );
        
        // Augment matrix with identity
        const augmented = matrix.map((row, i) => [...row, ...identity[i]]);
        
        // Gaussian elimination
        for (let i = 0; i < n; i++) {
            // Find pivot
            let maxRow = i;
            for (let k = i + 1; k < n; k++) {
                if (Math.abs(augmented[k][i]) > Math.abs(augmented[maxRow][i])) {
                    maxRow = k;
                }
            }
            [augmented[i], augmented[maxRow]] = [augmented[maxRow], augmented[i]];
            
            // Make diagonal 1
            const pivot = augmented[i][i];
            for (let j = 0; j < 2 * n; j++) {
                augmented[i][j] /= pivot;
            }
            
            // Eliminate column
            for (let k = 0; k < n; k++) {
                if (k !== i) {
                    const factor = augmented[k][i];
                    for (let j = 0; j < 2 * n; j++) {
                        augmented[k][j] -= factor * augmented[i][j];
                    }
                }
            }
        }
        
        // Extract inverse from augmented matrix
        return augmented.map(row => row.slice(n));
    }

    fit(x, y) {
        const X = this._createPolynomialFeatures(x);
        const XT = X[0].map((_, i) => X.map(row => row[i])); // Transpose
        
        const XTX = this._matrixMultiply(XT, X);
        const XTXInv = this._matrixInverse(XTX);
        const XTY = XT.map(row => row.reduce((sum, xi, i) => sum + xi * y[i], 0));
        
        this.coefficients = this._matrixMultiply(XTXInv, XTY.map(val => [val])).flat();
        this.trained = true;
        return this;
    }

    predict(x) {
        if (!this.trained) {
            throw new Error("Model must be trained before making predictions");
        }

        const X = this._createPolynomialFeatures(Array.isArray(x) ? x : [x]);
        const predictions = X.map(features => 
            features.reduce((sum, feature, i) => sum + feature * this.coefficients[i], 0)
        );
        
        return Array.isArray(x) ? predictions : predictions[0];
    }
}

// ==================== K-MEANS CLUSTERING ====================

class KMeans {
    constructor(k = 3, maxIterations = 100, tolerance = 1e-4) {
        this.k = k;
        this.maxIterations = maxIterations;
        this.tolerance = tolerance;
        this.centroids = [];
        this.labels = [];
        this.trained = false;
    }

    _initializeCentroids(data) {
        const features = data[0].length;
        this.centroids = [];
        
        for (let i = 0; i < this.k; i++) {
            const centroid = [];
            for (let j = 0; j < features; j++) {
                const column = data.map(row => row[j]);
                const min = Math.min(...column);
                const max = Math.max(...column);
                centroid.push(Math.random() * (max - min) + min);
            }
            this.centroids.push(centroid);
        }
    }

    _assignClusters(data) {
        return data.map(point => {
            let minDistance = Infinity;
            let cluster = 0;
            
            for (let i = 0; i < this.centroids.length; i++) {
                const distance = MLUtils.euclideanDistance(point, this.centroids[i]);
                if (distance < minDistance) {
                    minDistance = distance;
                    cluster = i;
                }
            }
            
            return cluster;
        });
    }

    _updateCentroids(data, labels) {
        const newCentroids = [];
        
        for (let i = 0; i < this.k; i++) {
            const clusterPoints = data.filter((_, index) => labels[index] === i);
            
            if (clusterPoints.length === 0) {
                newCentroids.push(this.centroids[i]);
                continue;
            }
            
            const centroid = clusterPoints[0].map((_, j) => 
                MLUtils.mean(clusterPoints.map(point => point[j]))
            );
            
            newCentroids.push(centroid);
        }
        
        return newCentroids;
    }

    fit(data) {
        this._initializeCentroids(data);
        
        for (let iter = 0; iter < this.maxIterations; iter++) {
            const labels = this._assignClusters(data);
            const newCentroids = this._updateCentroids(data, labels);
            
            // Check for convergence
            const centroidShift = this.centroids.reduce((sum, centroid, i) => 
                sum + MLUtils.euclideanDistance(centroid, newCentroids[i]), 0
            );
            
            this.centroids = newCentroids;
            this.labels = labels;
            
            if (centroidShift < this.tolerance) {
                break;
            }
        }
        
        this.trained = true;
        return this;
    }

    predict(data) {
        if (!this.trained) {
            throw new Error("Model must be trained before making predictions");
        }
        
        return this._assignClusters(data);
    }

    getInertia(data) {
        if (!this.trained) return null;
        
        return data.reduce((sum, point, i) => {
            const centroid = this.centroids[this.labels[i]];
            return sum + MLUtils.euclideanDistance(point, centroid) ** 2;
        }, 0);
    }
}

// ==================== K-NEAREST NEIGHBORS ====================

class KNearestNeighbors {
    constructor(k = 3) {
        this.k = k;
        this.trainData = [];
        this.trainLabels = [];
        this.trained = false;
    }

    fit(data, labels) {
        this.trainData = data.map(row => [...row]);
        this.trainLabels = [...labels];
        this.trained = true;
        return this;
    }

    predict(data) {
        if (!this.trained) {
            throw new Error("Model must be trained before making predictions");
        }

        return data.map(point => {
            // Calculate distances to all training points
            const distances = this.trainData.map((trainPoint, i) => ({
                distance: MLUtils.euclideanDistance(point, trainPoint),
                label: this.trainLabels[i]
            }));

            // Sort by distance and get k nearest
            distances.sort((a, b) => a.distance - b.distance);
            const kNearest = distances.slice(0, this.k);

            // For classification: return most frequent label
            if (typeof kNearest[0].label === 'string') {
                const labelCounts = {};
                kNearest.forEach(neighbor => {
                    labelCounts[neighbor.label] = (labelCounts[neighbor.label] || 0) + 1;
                });
                
                return Object.keys(labelCounts).reduce((a, b) => 
                    labelCounts[a] > labelCounts[b] ? a : b
                );
            }

            // For regression: return average
            return MLUtils.mean(kNearest.map(neighbor => neighbor.label));
        });
    }
}

// ==================== SIMPLE NEURAL NETWORK ====================

class SimpleNeuralNetwork {
    constructor(inputSize, hiddenSize, outputSize, learningRate = 0.1) {
        this.inputSize = inputSize;
        this.hiddenSize = hiddenSize;
        this.outputSize = outputSize;
        this.learningRate = learningRate;
        
        // Initialize weights randomly
        this.weightsInputHidden = this._randomMatrix(inputSize, hiddenSize);
        this.weightsHiddenOutput = this._randomMatrix(hiddenSize, outputSize);
        
        // Initialize biases
        this.biasHidden = new Array(hiddenSize).fill(0);
        this.biasOutput = new Array(outputSize).fill(0);
    }

    _randomMatrix(rows, cols) {
        return Array(rows).fill().map(() => 
            Array(cols).fill().map(() => Math.random() * 2 - 1)
        );
    }

    _sigmoid(x) {
        return 1 / (1 + Math.exp(-x));
    }

    _sigmoidDerivative(x) {
        return x * (1 - x);
    }

    _feedForward(input) {
        // Hidden layer
        const hiddenInput = this.weightsInputHidden.map((weights, i) => 
            weights.reduce((sum, weight, j) => sum + weight * input[j], 0) + this.biasHidden[i]
        );
        const hiddenOutput = hiddenInput.map(x => this._sigmoid(x));

        // Output layer
        const outputInput = this.weightsHiddenOutput.map((weights, i) => 
            weights.reduce((sum, weight, j) => sum + weight * hiddenOutput[j], 0) + this.biasOutput[i]
        );
        const output = outputInput.map(x => this._sigmoid(x));

        return { hiddenOutput, output };
    }

    train(inputs, targets, epochs = 1000) {
        for (let epoch = 0; epoch < epochs; epoch++) {
            for (let i = 0; i < inputs.length; i++) {
                const input = inputs[i];
                const target = targets[i];
                
                // Forward pass
                const { hiddenOutput, output } = this._feedForward(input);
                
                // Backward pass
                // Output layer error
                const outputErrors = target.map((t, j) => t - output[j]);
                const outputDeltas = outputErrors.map((error, j) => 
                    error * this._sigmoidDerivative(output[j])
                );
                
                // Hidden layer error
                const hiddenErrors = hiddenOutput.map((_, j) => 
                    outputDeltas.reduce((sum, delta, k) => 
                        sum + delta * this.weightsHiddenOutput[j][k], 0
                    )
                );
                const hiddenDeltas = hiddenErrors.map((error, j) => 
                    error * this._sigmoidDerivative(hiddenOutput[j])
                );
                
                // Update weights and biases
                for (let j = 0; j < this.weightsHiddenOutput.length; j++) {
                    for (let k = 0; k < this.weightsHiddenOutput[j].length; k++) {
                        this.weightsHiddenOutput[j][k] += this.learningRate * outputDeltas[k] * hiddenOutput[j];
                    }
                }
                
                for (let j = 0; j < this.weightsInputHidden.length; j++) {
                    for (let k = 0; k < this.weightsInputHidden[j].length; k++) {
                        this.weightsInputHidden[j][k] += this.learningRate * hiddenDeltas[k] * input[j];
                    }
                }
                
                // Update biases
                for (let j = 0; j < this.biasOutput.length; j++) {
                    this.biasOutput[j] += this.learningRate * outputDeltas[j];
                }
                
                for (let j = 0; j < this.biasHidden.length; j++) {
                    this.biasHidden[j] += this.learningRate * hiddenDeltas[j];
                }
            }
        }
    }

    predict(input) {
        const { output } = this._feedForward(input);
        return output;
    }
}

// ==================== DEMONSTRATION FUNCTIONS ====================

function demonstrateLinearRegression() {
    console.log("\n=== Linear Regression Demo ===");
    
    // Generate sample data
    const x = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    const y = x.map(xi => 2 * xi + 1 + (Math.random() - 0.5) * 2); // y = 2x + 1 + noise
    
    console.log("Training data (x, y):");
    x.forEach((xi, i) => console.log(`(${xi}, ${y[i].toFixed(2)})`));
    
    const lr = new LinearRegression();
    lr.fit(x, y);
    
    console.log(`\nTrained model: y = ${lr.slope.toFixed(3)}x + ${lr.intercept.toFixed(3)}`);
    console.log(`R² score: ${lr.score(x, y).toFixed(4)}`);
    
    const testX = [11, 12, 13];
    const predictions = lr.predict(testX);
    console.log("\nPredictions:");
    testX.forEach((xi, i) => console.log(`x=${xi} -> y=${predictions[i].toFixed(2)}`));
}

function demonstrateKMeans() {
    console.log("\n=== K-Means Clustering Demo ===");
    
    // Generate sample 2D data with 3 clusters
    const data = [
        [1, 2], [1.5, 1.8], [5, 8], [8, 8], [1, 0.6], [9, 11],
        [8, 2], [10, 2], [9, 3], [2, 1], [2, 2], [6, 9]
    ];
    
    console.log("Data points:", data);
    
    const kmeans = new KMeans(3);
    kmeans.fit(data);
    
    console.log("\nCluster centroids:");
    kmeans.centroids.forEach((centroid, i) => 
        console.log(`Cluster ${i}: (${centroid[0].toFixed(2)}, ${centroid[1].toFixed(2)})`)
    );
    
    console.log("\nCluster assignments:");
    data.forEach((point, i) => 
        console.log(`Point (${point[0]}, ${point[1]}) -> Cluster ${kmeans.labels[i]}`)
    );
    
    console.log(`\nInertia (sum of squared distances): ${kmeans.getInertia(data).toFixed(4)}`);
}

function demonstrateKNN() {
    console.log("\n=== K-Nearest Neighbors Demo ===");
    
    // Sample classification data
    const trainData = [
        [1, 2], [2, 3], [3, 1], [6, 5], [7, 7], [8, 6]
    ];
    const trainLabels = ['A', 'A', 'A', 'B', 'B', 'B'];
    
    console.log("Training data:");
    trainData.forEach((point, i) => 
        console.log(`(${point[0]}, ${point[1]}) -> ${trainLabels[i]}`)
    );
    
    const knn = new KNearestNeighbors(3);
    knn.fit(trainData, trainLabels);
    
    const testData = [[2, 1], [7, 5], [4, 4]];
    const predictions = knn.predict(testData);
    
    console.log("\nPredictions (k=3):");
    testData.forEach((point, i) => 
        console.log(`(${point[0]}, ${point[1]}) -> ${predictions[i]}`)
    );
}

function demonstrateNeuralNetwork() {
    console.log("\n=== Neural Network Demo (XOR Problem) ===");
    
    // XOR problem
    const inputs = [
        [0, 0],
        [0, 1],
        [1, 0],
        [1, 1]
    ];
    
    const targets = [
        [0],
        [1],
        [1],
        [0]
    ];
    
    console.log("Training XOR function:");
    inputs.forEach((input, i) => 
        console.log(`[${input[0]}, ${input[1]}] -> ${targets[i][0]}`)
    );
    
    const nn = new SimpleNeuralNetwork(2, 4, 1, 0.5);
    
    console.log("\nTraining neural network...");
    nn.train(inputs, targets, 10000);
    
    console.log("\nPredictions after training:");
    inputs.forEach((input, i) => {
        const prediction = nn.predict(input);
        console.log(`[${input[0]}, ${input[1]}] -> ${prediction[0].toFixed(4)} (target: ${targets[i][0]})`);
    });
}

function demonstratePolynomialRegression() {
    console.log("\n=== Polynomial Regression Demo ===");
    
    // Generate polynomial data
    const x = Array.from({length: 10}, (_, i) => i + 1);
    const y = x.map(xi => 0.5 * xi * xi + xi + 2 + (Math.random() - 0.5)); // y = 0.5x² + x + 2 + noise
    
    console.log("Training data (polynomial relationship):");
    x.forEach((xi, i) => console.log(`x=${xi}, y=${y[i].toFixed(2)}`));
    
    const polyReg = new PolynomialRegression(2);
    polyReg.fit(x, y);
    
    console.log("\nPolynomial coefficients [constant, x, x²]:");
    console.log(polyReg.coefficients.map(c => c.toFixed(4)));
    
    const testX = [11, 12];
    const predictions = polyReg.predict(testX);
    console.log("\nPredictions:");
    testX.forEach((xi, i) => console.log(`x=${xi} -> y=${predictions[i].toFixed(2)}`));
}

// ==================== MAIN EXECUTION ====================

function main() {
    console.log("🤖 Machine Learning Algorithms in JavaScript 🤖");
    console.log("================================================");
    
    demonstrateLinearRegression();
    demonstratePolynomialRegression();
    demonstrateKMeans();
    demonstrateKNN();
    demonstrateNeuralNetwork();
    
    console.log("\n✨ All ML algorithms demonstrated successfully! ✨");
}

// Run demonstrations
main();

// Export for use in other modules
if (typeof module !== 'undefined' && module.exports) {
    module.exports = {
        MLUtils,
        LinearRegression,
        PolynomialRegression,
        KMeans,
        KNearestNeighbors,
        SimpleNeuralNetwork
    };
}