/*The MIT License (MIT)

Copyright (c) 2016 Rand Dusing and contributors.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.*/

#import <Cordova/CDV.h>
#import <CoreBluetooth/CoreBluetooth.h>

@interface BluetoothLePlugin : CDVPlugin <CBCentralManagerDelegate, CBPeripheralDelegate>
{
    CBCentralManager *centralManager;
    NSNumber* statusReceiver;

    NSString* initCallback;
    NSString* scanCallback;

    NSMutableDictionary* connections;
}

- (void)initialize:(CDVInvokedUrlCommand *)command;
- (void)enable:(CDVInvokedUrlCommand *)command;
- (void)disable:(CDVInvokedUrlCommand *)command;
- (void)startScan:(CDVInvokedUrlCommand *)command;
- (void)stopScan:(CDVInvokedUrlCommand *)command;
- (void)retrieveConnected:(CDVInvokedUrlCommand *)command;
- (void)connect:(CDVInvokedUrlCommand *)command;
- (void)reconnect:(CDVInvokedUrlCommand *)command;
- (void)disconnect:(CDVInvokedUrlCommand *)command;
- (void)close:(CDVInvokedUrlCommand *)command;
- (void)discover:(CDVInvokedUrlCommand *)command;
- (void)services:(CDVInvokedUrlCommand *)command;
- (void)characteristics:(CDVInvokedUrlCommand *)command;
- (void)descriptors:(CDVInvokedUrlCommand *)command;
- (void)read:(CDVInvokedUrlCommand *)command;
- (void)subscribe:(CDVInvokedUrlCommand *)command;
- (void)unsubscribe:(CDVInvokedUrlCommand *)command;
- (void)write:(CDVInvokedUrlCommand *)command;
- (void)readDescriptor:(CDVInvokedUrlCommand *)command;
- (void)writeDescriptor:(CDVInvokedUrlCommand *)command;
- (void)rssi:(CDVInvokedUrlCommand *)command;
- (void)mtu:(CDVInvokedUrlCommand *)command;
- (void)requestConnectionPriority:(CDVInvokedUrlCommand *)command;
- (void)isInitialized:(CDVInvokedUrlCommand *)command;
- (void)isEnabled:(CDVInvokedUrlCommand *)command;
- (void)isScanning:(CDVInvokedUrlCommand *)command;
- (void)isConnected:(CDVInvokedUrlCommand *)command;
- (void)isDiscovered:(CDVInvokedUrlCommand *)command;
- (void)hasPermission:(CDVInvokedUrlCommand *)command;
- (void)requestPermission:(CDVInvokedUrlCommand *)command;
- (void)isLocationEnabled:(CDVInvokedUrlCommand *)command;

@end

//Taken from http://stackoverflow.com/questions/13275859/how-to-turn-cbuuid-into-string, thanks Brad Larson

@interface CBUUID (StringExtraction)

- (NSString *)representativeString;

@end

@implementation CBUUID (StringExtraction)

- (NSString *)representativeString;
{
    NSData *data = [self data];

    NSUInteger bytesToConvert = [data length];
    const unsigned char *uuidBytes = [data bytes];
    NSMutableString *outputString = [NSMutableString stringWithCapacity:16];

    for (NSUInteger currentByteIndex = 0; currentByteIndex < bytesToConvert; currentByteIndex++)
    {
        switch (currentByteIndex)
        {
            case 3:
            case 5:
            case 7:
            case 9:[outputString appendFormat:@"%02x-", uuidBytes[currentByteIndex]]; break;
            default:[outputString appendFormat:@"%02x", uuidBytes[currentByteIndex]];
        }

    }

    return outputString;
}

@end
