# C++ Crow Web Framework Using SSL Certificate

### Follow steps to generate a Self Signed Certificate 

## Run as Root
``sudo su``

## Generate a private key

``openssl genpkey -algorithm RSA -out localhost.key``

I am testing this certificate on Ubuntu localhost (127.0.0.1), so I named it "localhost.key".

## Generate a Certificate Signing Request (CSR):

Create a CSR file, which will be used to generate the self-signed certificate. Replace your_csr.csr with the desired name for your CSR file:

``openssl req -new -key your_key.key -out localhost_csr.csr``

## Follow the prompts to enter information such as your Common Name (CN). 
when asked for Common Name you should typically be set to <b>localhost</b> for localhost testing.

## Use the CSR to generate the self-signed certificate. 
Replace your_cert.crt with the desired name for your certificate file:

``openssl x509 -req -days 365 -in localhost_csr.csr -signkey localhost.key -out localhost.crt``

I am using <b>localhost_csr.csr</b> and <b>localhost.key</b>, which we previously generated.

## .crt and .key files are generated in home directory
Copy those two files to the root directory of your project.

