#ifndef certs_h
#define certs_h
// Amazon's root CA. This should be the same for everyone.
const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIE0zCCA7ugAwIBAgIQGNrRniZ96LtKIVjNzGs7SjANBgkqhkiG9w0BAQUFADCB
yjELMAkGA1UEBhMCVVMxFzAVBgNVBAoTDlZlcmlTaWduLCBJbmMuMR8wHQYDVQQL
ExZWZXJpU2lnbiBUcnVzdCBOZXR3b3JrMTowOAYDVQQLEzEoYykgMjAwNiBWZXJp
U2lnbiwgSW5jLiAtIEZvciBhdXRob3JpemVkIHVzZSBvbmx5MUUwQwYDVQQDEzxW
ZXJpU2lnbiBDbGFzcyAzIFB1YmxpYyBQcmltYXJ5IENlcnRpZmljYXRpb24gQXV0
aG9yaXR5IC0gRzUwHhcNMDYxMTA4MDAwMDAwWhcNMzYwNzE2MjM1OTU5WjCByjEL
MAkGA1UEBhMCVVMxFzAVBgNVBAoTDlZlcmlTaWduLCBJbmMuMR8wHQYDVQQLExZW
ZXJpU2lnbiBUcnVzdCBOZXR3b3JrMTowOAYDVQQLEzEoYykgMjAwNiBWZXJpU2ln
biwgSW5jLiAtIEZvciBhdXRob3JpemVkIHVzZSBvbmx5MUUwQwYDVQQDEzxWZXJp
U2lnbiBDbGFzcyAzIFB1YmxpYyBQcmltYXJ5IENlcnRpZmljYXRpb24gQXV0aG9y
aXR5IC0gRzUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQCvJAgIKXo1
nmAMqudLO07cfLw8RRy7K+D+KQL5VwijZIUVJ/XxrcgxiV0i6CqqpkKzj/i5Vbex
t0uz/o9+B1fs70PbZmIVYc9gDaTY3vjgw2IIPVQT60nKWVSFJuUrjxuf6/WhkcIz
SdhDY2pSS9KP6HBRTdGJaXvHcPaz3BJ023tdS1bTlr8Vd6Gw9KIl8q8ckmcY5fQG
BO+QueQA5N06tRn/Arr0PO7gi+s3i+z016zy9vA9r911kTMZHRxAy3QkGSGT2RT+
rCpSx4/VBEnkjWNHiDxpg8v+R70rfk/Fla4OndTRQ8Bnc+MUCH7lP59zuDMKz10/
NIeWiu5T6CUVAgMBAAGjgbIwga8wDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8E
BAMCAQYwbQYIKwYBBQUHAQwEYTBfoV2gWzBZMFcwVRYJaW1hZ2UvZ2lmMCEwHzAH
BgUrDgMCGgQUj+XTGoasjY5rw8+AatRIGCx7GS4wJRYjaHR0cDovL2xvZ28udmVy
aXNpZ24uY29tL3ZzbG9nby5naWYwHQYDVR0OBBYEFH/TZafC3ey78DAJ80M5+gKv
MzEzMA0GCSqGSIb3DQEBBQUAA4IBAQCTJEowX2LP2BqYLz3q3JktvXf2pXkiOOzE
p6B4Eq1iDkVwZMXnl2YtmAl+X6/WzChl8gGqCBpH3vn5fJJaCGkgDdk+bW48DW7Y
5gaRQBi5+MHt39tBquCWIMnNZBU4gcmU7qKEKQsTb47bDN0lAtukixlE0kF6BWlK
WE9gyn6CagsCqiUXObXbf+eEZSqVir2G3l6BFoMtEMze/aiCKm0oHw0LxOXnGiYZ
4fQRbxC1lfznQgUy286dUV4otp6F01vvpX1FQHKOtw5rDgb7MzVIcbidJ4vEZV8N
hnacRHr2lVz2XTIIM6RUthg/aFzyQkqFOFSDX9HoLPKsEdao7WNq
-----END CERTIFICATE-----
)EOF";
// The private key for your device
const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEpAIBAAKCAQEA55siceEFCGVbB0UBhoZD90XlS0CSvBsVRMFNGU2DLU0sngOL
ILaYpySO+rTFs87T8/WxqVvllbXjUFsPT4ua79TFRBNYwPdyv5XoTqTYRYkwFyca
ilfMZVudMzUbwDlgkz0N/M1j0S3gu5QkZc75LBFSugvv3cXSw++aFuxevWrb+EMF
K+EgNfi4Ky3NTJQcnBS2/j/4FiUw8E/wt0vJa1EEZInlto4XOuzH/91sYWLKQ3jC
b+W210468Ym4es/H1Lf/7VT/Ohs4xYnp8t2HFtpi8It/5lGjAS6dkvlzoQv6gZ71
ME776o4kCwzVUSifNkdvqEaXqlFoa6SfQgA2ewIDAQABAoIBAE9gZty6rxviiOEj
8FLnn1GW/e/dkKyxZ4ep7D+YxjV3dqwtMLikfAsEx4/69qsaXqAE+7+8hCHcNazr
mIK9qPs7Y+Rh8RApfoVU3kpdytWCIB4/Q6RYVPAEBwtuzzUBNS0hRrL2vZgKbjQ7
oIHX/qPwx/aFcs8CJqsKajgjCJFH8HNQY5RMZ58uRWOo6uzdwL8jQGeR/pVcZ4/2
tvl66PTErOclupPxCt5uS6ehOwat3aHJMfyla0y5xvKUCyc0T49XH2/GH8rfKkX8
qaguN8SdfSLwfhlokVz0uAvtqaL4jqST1/5AHfuqiRqjNDyuNOkLP3YaK0pQCosA
TB8x3FECgYEA9hQxKztrMlz4LjiAGrRUqZb0luXd/UHC6Mf0wYvIJBscuS/v+lc9
SwXgWwknYDyEPOiNGblWQR+Q3P4bjKLX8RQUpB4cheKwhrlAT/jToZeTWSDXhgzi
8aCZqUixrEuv9E2MPurCNPAXiMYVAJ4FfSRQudG3WEGvoTwoysSfHyMCgYEA8PGQ
9TSs0g3GHriDbc06LTkHphBatNg/cMNKhZKMnFMGDscb/b+4ZFvgyJPz6su96uA6
YmdPB7rZsY8kwFyv5nwtP5/hWEQQcrujqE4hju9P9DseG/9bFJBkwQoarBMgTjkP
Rlu0mPr7T4T5HsYNVZKg8CfCgmLzwx23fqY6bMkCgYEA9SLsUEri4MromPLD+tZF
uKOeiGv5Fn9aMRZwZhZfjEhN9tUgVNxvPLtf4pBd32qpuRtY5JVSrZFKeDvTKehX
AdulLFCqzV0jyTHmNUSFXmZm7NTgnrNbqKT6Lj8yb5b+c3qFCXBHgwDiEOhyp6jD
gwSYPmQCJzNYSGBrqoLwmM0CgYEA2jvy8CYl4pxXNrwpTur0JsHhC6kEf4je7WP1
u8ZhVbZdZkUyNUPR4BTYJNTduW2RN4yhVT/9dSLoysq8nv9U047l7RsDIM+FlmYe
dfNOsghQgwaI3xMLjDS9DZv5TKKGQFOuYivuCCJMPlpSymzY5wlIfD2HEFJQOApS
iYRGpwECgYAGGaQtfO9JgRRIgS8lX5GbBDkSfQXwi5lPYabBvYelMriETHpzFVMq
A1CyEebJCN3DI0dyRdP8yo9tUpSo02fNCGftlN2sXhjusosDCMKaRfxKLngnrmRB
aDGjpiyGZ0VHt6xbLKeqZ96KUPl91nga9JSDEdKJzoZ6Ezf0GFxLZw==
-----END RSA PRIVATE KEY-----
)KEY";
// The certificate for your device
const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVAOM2nOPjTZmtuM66Wpd9m7lpE8GPMA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yMDA4MTEwOTMz
MDRaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDnmyJx4QUIZVsHRQGG
hkP3ReVLQJK8GxVEwU0ZTYMtTSyeA4sgtpinJI76tMWzztPz9bGpW+WVteNQWw9P
i5rv1MVEE1jA93K/lehOpNhFiTAXJxqKV8xlW50zNRvAOWCTPQ38zWPRLeC7lCRl
zvksEVK6C+/dxdLD75oW7F69atv4QwUr4SA1+LgrLc1MlBycFLb+P/gWJTDwT/C3
S8lrUQRkieW2jhc67Mf/3WxhYspDeMJv5bbXTjrxibh6z8fUt//tVP86GzjFieny
3YcW2mLwi3/mUaMBLp2S+XOhC/qBnvUwTvvqjiQLDNVRKJ82R2+oRpeqUWhrpJ9C
ADZ7AgMBAAGjYDBeMB8GA1UdIwQYMBaAFNbYBAdYcpxOyvRNNDmGIDLHNIpIMB0G
A1UdDgQWBBS9JRdOeuCsmTIthGZYxf6wwl1fOTAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEALYx9XTpp9sUH+EG58GV1of2s
HOF0P0F+6Wgrgor4TO2Q63ghHU26MMg0APbmcGYCiXUDmefifaqffVZS2hYxFQ0h
4ovJORVuhpwuyx2lmXtUX4W82kMxzJApLVxk02FdEjcM8tTsCpkOXJ5czH43PFOt
6SYQxNrs5QHVIPX1+Bl56+ImAJJ4WRERuYRWMTdcTK0UdW/eL+Vz6i+dypKJbF3R
HBuvBW+EVWONznERy59NQ9/YHgfiMOYMUZVJIGSm1BUTakztGkjK/HqJOnAY2VAd
K0bbC+LG3Qr1SUafmIufzl2/5KNrZa/9XEACOrplashWB2BqxZpfVE8a3kNWMQ==
-----END CERTIFICATE-----
)KEY";
#endif