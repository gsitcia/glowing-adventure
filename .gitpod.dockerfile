FROM ndless/ndless-sdk:latest
USER root
RUN chown -R gitpod:gitpod /ndless-sdk

FROM gitpod/workspace-full:latest
RUN mkdir /ndless-sdk
COPY --from=0 /ndless-sdk /ndless-sdk
