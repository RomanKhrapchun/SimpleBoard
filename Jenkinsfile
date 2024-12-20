pipeline {
    agent any

    environment {
        DOCKER_HUB_CREDENTIALS = credentials('docker-hub-credentials')
        DOCKER_IMAGE_NAME = 'romankhrapchnun/simpleboard'
        OS_PARAM = 'ubuntu'
    }

    stages {
        stage('Checkout') {
            steps {
                echo 'Checking out the code...'
                checkout scm
            }
        }
        stage('Build Docker Image') {
            steps {
                echo 'Building the Docker image...'
                sh '''
                    docker build -t $DOCKER_IMAGE_NAME .
                '''
            }
        }
        stage('Test Docker Image') {
            steps {
                echo 'Running tests in Docker container...'
                sh '''
                    docker run --rm $DOCKER_IMAGE_NAME ./run_tests.sh $OS_PARAM
                '''
            }
        }
        stage('Push Docker Image to Docker Hub') {
            steps {
                echo 'Pushing Docker image to Docker Hub...'
                sh '''
                    echo $DOCKER_HUB_CREDENTIALS_PSW | docker login -u $DOCKER_HUB_CREDENTIALS_USR --password-stdin
                    docker push $DOCKER_IMAGE_NAME
                    docker logout
                '''
            }
        }
        stage('Run Container and Collect Output') {
            steps {
                echo 'Running Docker container to generate output files...'
                sh '''
                    docker run --rm -v $(pwd)/output:/app/output $DOCKER_IMAGE_NAME
                '''
            }
        }
        stage('Upload Output Files to S3') {
            steps {
                echo 'Uploading output files to S3...'
                withAWS(credentials: 'aws-credentials', region: 'eu-north-1') {
                    s3Upload(bucket: 'jenkins-sonarqube-builds-k1z6vsfz', file: 'output/', path: 'artifacts/output/')
                }
            }
        }
    }

    post {
        success {
            echo 'Pipeline завершено успішно!'
        }
        failure {
            echo 'Pipeline завершено з помилкою.'
        }
    }
}
