/**
 *  MIT License
 *
 *  Copyright (c) 2017 Richard Moore <me@ricmoo.com>
 *
 *  Permission is hereby granted, free of charge, to any person obtaining
 *  a copy of this software and associated documentation files (the
 *  "Software"), to deal in the Software without restriction, including
 *  without limitation the rights to use, copy, modify, merge, publish,
 *  distribute, sublicense, and/or sell copies of the Software, and to
 *  permit persons to whom the Software is furnished to do so, subject to
 *  the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included
 *  in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 *  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 *  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *  DEALINGS IN THE SOFTWARE.
 */

#import <Foundation/Foundation.h>
#import "Address.h"
#import "BigNumber.h"
#import "Hash.h"
#import "Signature.h"

typedef NS_OPTIONS(unsigned char, ChainId)  {
    ChianIdAny          = 0x00,
    ChainIdHomestead    = 0x01,
    ChainIdMorden       = 0x02,
    ChainIdRopsten      = 0x03,
    ChainIdRinkeby      = 0x04,
    ChainIdKovan        = 0x2a,
};

extern NSString * _Nullable chainName(ChainId chainId);
@class Account;
//typedef unsigned long long Nonce;


@interface Transaction : NSObject

+ (nonnull instancetype)transaction;
+ (nonnull instancetype)transactionWithFromAddress: (nonnull Address*)fromAddress;

+ (nonnull instancetype)transactionWithData: (nonnull NSData*)transactionData;

@property (nonatomic, assign) NSUInteger nonce;

@property (nonatomic, strong, nonnull) BigNumber *gasPrice;
@property (nonatomic, strong, nonnull) BigNumber *gasLimit;

@property (nonatomic, strong, nullable) Address *toAddress;
@property (nonatomic, strong, nonnull) BigNumber *value;

@property (nonatomic, strong, nonnull) NSData *dependsOn;


@property (nonatomic, strong, nonnull) NSData *data;

@property (nonatomic, strong, nullable) Signature *signature;

@property (nonatomic, readonly, nullable) Address *fromAddress;

@property (nonatomic, assign) ChainId chainId;

@property (nonatomic, assign) NSInteger Expiration;
@property (nonatomic, strong, nonnull) BigNumber *ChainTag;
@property (nonatomic, strong, nonnull) BigNumber *BlockRef;
@property (nonatomic, strong, nonnull) NSArray *Clauses;

- (NSString *_Nullable)txID:(Account *_Nonnull)account;

- (nonnull NSData*)serialize;

- (nonnull NSData*)unsignedSerialize;

- (BOOL)populateSignatureWithR: (nonnull NSData*)r s: (nonnull NSData*)s address: (nonnull Address*)address;


@property (nonatomic, readonly, nullable) Hash *transactionHash;

- (NSString *_Nullable)obersverTxID:(NSString *_Nullable)address;

- (NSData *_Nullable)getSigntureMessage;

@end
