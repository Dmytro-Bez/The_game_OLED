#ifndef certs_h
#define certs_h
// Amazon's root CA. This should be the same for everyone.
const char aws_cert_ca[] PROGMEM = R"EOF(

)EOF";
// The private key for your device
const char aws_cert_private[] PROGMEM = R"KEY(

)KEY";
// The certificate for your device
const char aws_cert_crt[] PROGMEM = R"KEY(

)KEY";
#endif