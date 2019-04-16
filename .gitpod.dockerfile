FROM ndless/ndless-sdk:latest
USER root
RUN chown -R root /ndless-sdk

FROM gitpod/workspace-full:latest
RUN mkdir /ndless-sdk
COPY --from=0 /ndless-sdk /ndless-sdk
