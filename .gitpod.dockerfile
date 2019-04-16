FROM ndless/ndless-sdk:latest
USER root
RUN chown -R root:root /ndless-sdk

FROM gitpod/workspace-full:latest
USER root
RUN mkdir /ndless-sdk
COPY --from=0 /ndless-sdk /ndless-sdk
RUN chown -R gitpod:gitpod /ndless-sdk