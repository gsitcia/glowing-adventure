FROM gitpod/workspace-full:latest

USER root

#install docker so we can use ndless...
RUN apt-get update \
    && apt-get install -yq apt-transport-https ca-certificates curl software-properties-common \
    && curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add - \
    && add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu bionic stable" \
    && apt-get update \
    && apt-cache policy docker-ce \
#    && apt-get -yq install docker-ce \
    && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* \
#    && gpasswd -a gitpod docker
