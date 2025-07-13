ARG BASE_IMAGE_VER="24.04"
ARG ARTIFACTS_PATH="./artifacts"

FROM ubuntu:${BASE_IMAGE_VER} AS deployment-stage
ARG ARTIFACTS_PATH
# Step 1: set working directory
WORKDIR /opt/calculator
# Step 2: copy artifacts
RUN mkdir -p /tmp/calculator
COPY ${ARTIFACTS_PATH}/* /tmp/calculator/
# Step 3: install calculator app
RUN apt update && apt install -y \
    /tmp/calculator/calculator_*.deb

FROM deployment-stage AS final-stage
ENV APP_ARGS="-u"
RUN chmod +x /opt/calculator/AppRun
# Step 1: set entrypoint
ENTRYPOINT ["sh", "-c", "/opt/calculator/AppRun $APP_ARGS"]
