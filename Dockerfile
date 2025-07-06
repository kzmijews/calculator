ARG BASE_IMAGE_VER="24.04"
ARG ARTIFACTS_PATH="./artifacts"

FROM ubuntu:${BASE_IMAGE_VER} AS deployment-stage
ARG ARTIFACTS_PATH
# Step 1: set working directory
WORKDIR /opt/calculator
# Step 2: install dependencies
RUN apt update && apt install -y \
    libegl1 \
    libfontconfig1 \
    libgl1
# Step 3: copy artifacts
RUN mkdir -p /opt/calculator
COPY ${ARTIFACTS_PATH}/* /opt/calculator/

FROM deployment-stage AS final-stage
ENV APP_ARGS="-u"
# Step 1: set entrypoint
ENTRYPOINT ["sh", "-c", "./bin/calculator $APP_ARGS"]