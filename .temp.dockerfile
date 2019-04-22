FROM gitpod/workspace-full:latest
USER root
RUN adduser --system --no-create-home --uid 198869 --gid 198869 bob
USER bob
COPY --from=0 /ndless-sdk /ndless-sdk
USER root
RUN chown gitpod:gitpod /ndless-sdk
RUN apt-get update \
    && apt-get install -yq libmpc-dev libmpfr-dev libgmp-dev \
    && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* \
