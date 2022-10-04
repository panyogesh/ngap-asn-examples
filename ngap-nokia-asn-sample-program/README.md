## Welcome to the NGAP ASN Installer guide

### Installing the asn1c compiler
* git clone https://github.com/nokia/asn1c.git
* cd asn1c
* automake --version
* sudo apt-get -y install libtool 
* sudo apt-get -y install flex
* sudo apt-get -y install bison
* test -f configure || autoreconf -iv
* ./configure
* make
* sudo make install


### Refer to asn-extract-from-docs for getting the asn entries from PDF for NGP

### Install the files for asn
* cd <PATH>/ngap-asn-examples/ngap-nokia-asn-sample-program 
* asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps  -no-gen-OER  -gen-PER -D . ../ngap-asn.txt 
* rm converter-example.*
* Following patch required for ProtocolExtensionField.c
------------------------------------------------------
vagrant@distro-magma:~/TMP$ diff ProtocolExtensionField.c.orig ProtocolExtensionField.c
39196c39196
<               { 0, &asn_PER_memb_OCTET_STRING_CONTAINING_PDUSessionResourceReleaseResponseTransfer__constr_42,  memb_OCTET_STRING_CONTAINING_PDUSessionResourceReleaseResponseTransfer__constraint_628 },
---
>               { 0, 0,  memb_OCTET_STRING_CONTAINING_PDUSessionResourceReleaseResponseTransfer__constraint_628 },
------------------------------------------------------

### Build and run the sample code of modified_main_asn.c
* mkdir build
* cd build
* cmake ..
* make
* ./modified_main_asn
