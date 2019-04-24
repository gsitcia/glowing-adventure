export PATH=$PATH:/ndless-sdk/bin:/ndless-sdk/toolchain/install/bin
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
cp /ndless-sdk/thirdparty/zlib/zlib.h /ndless-sdk/include/
cp /ndless-sdk/thirdparty/zlib/zconf.h /ndless-sdk/include/