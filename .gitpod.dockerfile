FROM gitpod/workspace-full:latest

COPY --from=ndless/ndless-sdk:latest /ndless-sdk/ /ndless-sdk
