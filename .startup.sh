cd /ndless-sdk/thirdparty/nspire-io/
make lib
cp -r lib/ /ndless-sdk/
cp -r include/ /ndless-sdk/
cd /ndless-sdk/libndls/
make
cd /ndless-sdk/libsyscalls/
make
cd /ndless-sdk/tools/genzehn
make
