FROM gitpod/workspace-full:latest

USER root

# Install ndless toolchain dependencies
# libmpc3, libmpfr6, libgmp-dev, libpython2.7
RUN apt-get update \
    && apt-get install -yq libmpc-dev libmpfr-dev libgmp-dev libpython2.7 \
    && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/*
