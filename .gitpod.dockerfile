FROM gitpod/workspace-full

# add your tools here
USER root
RUN apt-get update
RUN apt-get install libgmp-dev
RUN apt-get install libpython2.7-stdlib
RUN apt-get clean && rm -rf /var/cache/apt/* && rm -rf /var/lib/apt/lists/* && rm -rf /tmp/*

