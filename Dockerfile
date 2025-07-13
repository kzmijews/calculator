# Copyright © 2025 Karol Zmijewski
#
# Permission is hereby granted, free of charge, to any person obtaining a copy of this
# software and associated documentation files (the “Software”), to deal in the Software
# without restriction, including without limitation the rights to use, copy, modify, merge,
# publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons
# to whom the Software is furnished to do so, subject to the following conditions:
# The above copyright notice and this permission notice shall be included in all copies or
# substantial portions of the Software.
# THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
#
# INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
# PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
# FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
# OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
# DEALINGS IN THE SOFTWARE.

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
