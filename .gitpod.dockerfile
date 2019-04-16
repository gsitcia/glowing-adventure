FROM gitpod/workspace-full:latest

COPY --from=ndless/ndless-sdk /ndless-sdk/ /
