FROM gitpod/workspace-full:latest

USER root

# Install ndless toolchain dependencies
# libmpc3, libmpfr6, libgmp-dev, libpython2.7, texinfo
RUN apt-get update \
    && apt-cache search docker \
    && apt-get install -yq libmpc-dev libmpfr-dev libgmp-dev python2.7-dev texinfo docker \
    && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/*

RUN groupadd docker && gpasswd -a gitpod docker
