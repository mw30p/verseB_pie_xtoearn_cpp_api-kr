/*
 * VerseB.h
 *
 *  Created on: 2022. 7. 1.
 *      Author: NextBankDev
 */

#ifndef INCLUDE_VERSEB_H_
#define INCLUDE_VERSEB_H_

#include <consts.h>

typedef struct exchangeRate_IN {
	char	merchantId[MERCHANT_ID_SZ];
	char	merchantSiteId[MERCHANT_SITE_ID_SZ];
	char	customerId[CUSTOMER_ID_SZ];
	char	fromCurrency[FROM_CURRENCY_SZ];
	char	toCurrency[TO_CURRENCY_SZ];
	char	fromAmount[FROM_AMOUNT_SZ];
	char	key[KEY_SZ];
	char	initialVector[INITIAL_VECTOR_SZ];
} exRate_IN;

typedef struct exchangeRate_OUT {
	char	merchantId[MERCHANT_ID_SZ];
	char	merchantSiteId[MERCHANT_SITE_ID_SZ];
	char	code[CODE_SZ];
	char	customerId[CUSTOMER_ID_SZ];
	char	fromCurrency[FROM_CURRENCY_SZ];
	char	toCurrency[TO_CURRENCY_SZ];
	char	fromAmount[FROM_AMOUNT_SZ];
	char	toAmount[TO_AMOUNT_SZ];
	char	exchangeRate[EXCHANGE_RATE_SZ];
	char	status[STATUS_SZ];
	char	errCd[ERR_CD_SZ];
	char	reason[REASON_SZ];
} exRate_OUT;

typedef struct exchangeReq_IN {
	char	merchantId[MERCHANT_ID_SZ];
	char	merchantSiteId[MERCHANT_SITE_ID_SZ];
	char	customerId[CUSTOMER_ID_SZ];
	char	fromCurrency[FROM_CURRENCY_SZ];
	char	toCurrency[TO_CURRENCY_SZ];
	char	fromAmount[FROM_AMOUNT_SZ];
	char	exchangeRate[EXCHANGE_RATE_SZ];
	char	outPassword[OUT_PASSWORD_SZ];
	char	Papers[PAPERS_SZ];
	char	notifyUrl[NOTIFY_URL_SZ];
	char	key[KEY_SZ];
	char	initialVector[INITIAL_VECTOR_SZ];
} exReq_IN;

typedef struct exchangeReq_OUT {
	char	merchantId[MERCHANT_ID_SZ];
	char	merchantSiteId[MERCHANT_SITE_ID_SZ];
	char	code[CODE_SZ];
	char	customerId[CUSTOMER_ID_SZ];
	char	fromCurrency[FROM_CURRENCY_SZ];
	char	toCurrency[TO_CURRENCY_SZ];
	char	fromAmount[FROM_AMOUNT_SZ];
	char	toAmount[TO_AMOUNT_SZ];
	char	exchangeRate[EXCHANGE_RATE_SZ];
	char	internalAddress[INTERNAL_ADDRESS_SZ];
	char	txId[TX_ID_SZ];
	char	status[STATUS_SZ];
	char	errCd[ERR_CD_SZ];
	char	reason[REASON_SZ];
} exReq_OUT;

typedef struct outAddrVerify_IN {
	char	merchantId[MERCHANT_ID_SZ];
	char	merchantSiteId[MERCHANT_SITE_ID_SZ];
	char	customerId[CUSTOMER_ID_SZ];
	char	outAddress[OUT_ADDRESS_SZ];
	char	outPassword[OUT_PASSWORD_SZ];
	char	Papers[PAPERS_SZ];
	char	key[KEY_SZ];
	char	initialVector[INITIAL_VECTOR_SZ];
} outAddr_IN;

typedef struct outAddrVerify_OUT {
	char	merchantId[MERCHANT_ID_SZ];
	char	merchantSiteId[MERCHANT_SITE_ID_SZ];
	char	code[CODE_SZ];
	char	customerId[CUSTOMER_ID_SZ];
	char	outAddress[OUT_ADDRESS_SZ];
	char	status[STATUS_SZ];
	char	errCd[ERR_CD_SZ];
	char	reason[REASON_SZ];
} outAddr_OUT;

typedef struct passport_IN {
	char	merchantId[MERCHANT_ID_SZ];
	char	merchantSiteId[MERCHANT_SITE_ID_SZ];
	char	customerId[CUSTOMER_ID_SZ];
	char	PassportOption[PASSPORT_OPTION_SZ];
	char	outPassword[OUT_PASSWORD_SZ];
	char	newPassword[NEW_PASSWORD_SZ];
	char	Papers[PAPERS_SZ];
	char	key[KEY_SZ];
	char	initialVector[INITIAL_VECTOR_SZ];
} pass_IN;

typedef struct passport_OUT {
	char	merchantId[MERCHANT_ID_SZ];
	char	merchantSiteId[MERCHANT_SITE_ID_SZ];
	char	code[CODE_SZ];
	char	customerId[CUSTOMER_ID_SZ];
	char	Papers[PAPERS_SZ];
	char	status[STATUS_SZ];
	char	errCd[ERR_CD_SZ];
	char	reason[REASON_SZ];
} pass_OUT;

typedef struct reqPreTrade_IN {
	char	merchantId[MERCHANT_ID_SZ];
	char	merchantSiteId[MERCHANT_SITE_ID_SZ];
	char	code[CODE_SZ];
	char	customerId[CUSTOMER_ID_SZ];
	char	fromCurrency[FROM_CURRENCY_SZ];
	char	toCurrency[TO_CURRENCY_SZ];
	char	fromAmount[FROM_AMOUNT_SZ];
	char	key[KEY_SZ];
	char	initialVector[INITIAL_VECTOR_SZ];
} preTrade_IN;

typedef struct reqPreTrade_OUT {
	char	merchantId[MERCHANT_ID_SZ];
	char	merchantSiteId[MERCHANT_SITE_ID_SZ];
	char	code[CODE_SZ];
	char	customerId[CUSTOMER_ID_SZ];
	char	outAddress[OUT_ADDRESS_SZ];
	char	fromCurrency[FROM_CURRENCY_SZ];
	char	toCurrency[TO_CURRENCY_SZ];
	char	fromAmount[FROM_AMOUNT_SZ];
	char	withdrawalRate[WITHDRAWAL_RATE_SZ];
	char	toAmount[TO_AMOUNT_SZ];
	char	withdrawalFee[WITHDRAWAL_FEE_SZ];
	char	withdrawalAmount[WITHDRAWAL_AMOUNT_SZ];
	char	ReserveWID[RESERVE_WID_SZ];
	char	pinNumber[PIN_NUMBER_SZ];
	char	status[STATUS_SZ];
	char	errCd[ERR_CD_SZ];
	char	reason[REASON_SZ];
} preTrade_OUT;

typedef struct reqWithdraw_IN {
	char	merchantId[MERCHANT_ID_SZ];
	char	merchantSiteId[MERCHANT_SITE_ID_SZ];
	char	customerId[CUSTOMER_ID_SZ];
	char	outAddress[OUT_ADDRESS_SZ];
	char	fromCurrency[FROM_CURRENCY_SZ];
	char	toCurrency[TO_CURRENCY_SZ];
	char	fromAmount[FROM_AMOUNT_SZ];
	char	withdrawalRate[WITHDRAWAL_RATE_SZ];
	char	toAmount[TO_AMOUNT_SZ];
	char	withdrawalFee[WITHDRAWAL_FEE_SZ];
	char	withdrawalAmount[WITHDRAWAL_AMOUNT_SZ];
	char	ReserveWID[RESERVE_WID_SZ];
	char	pinNumber[PIN_NUMBER_SZ];
	char	outPassword[OUT_PASSWORD_SZ];
	char	Papers[PAPERS_SZ];
	char	notifyUrl[NOTIFY_URL_SZ];
	char	key[KEY_SZ];
	char	initialVector[INITIAL_VECTOR_SZ];
} reqWdraw_IN;

typedef struct reqWithdraw_OUT {
	char	merchantId[MERCHANT_ID_SZ];
	char	merchantSiteId[MERCHANT_SITE_ID_SZ];
	char	code[CODE_SZ];
	char	customerId[CUSTOMER_ID_SZ];
	char	outAddress[OUT_ADDRESS_SZ];
	char	fromCurrency[FROM_CURRENCY_SZ];
	char	toCurrency[TO_CURRENCY_SZ];
	char	fromAmount[FROM_AMOUNT_SZ];
	char	withdrawalRate[WITHDRAWAL_RATE_SZ];
	char	toAmount[TO_AMOUNT_SZ];
	char	withdrawalFee[WITHDRAWAL_FEE_SZ];
	char	withdrawalAmount[WITHDRAWAL_AMOUNT_SZ];
	char	txId[TX_ID_SZ];
	char	status[STATUS_SZ];
	char	errCd[ERR_CD_SZ];
	char	reason[REASON_SZ];
} reqWdraw_OUT;

extern int iMode;

int exRate(exRate_IN *in,			exRate_OUT *out);
int exReq(exReq_IN *in,				exReq_OUT *out);
int outAddr(outAddr_IN *in,			outAddr_OUT *out);
int Passport(pass_IN *in,			pass_OUT *out);
int reqPreTrade(preTrade_IN *in,		preTrade_OUT *out);
int reqWithdraw(reqWdraw_IN *in,	reqWdraw_OUT *out);

#endif /* INCLUDE_VERSEB_H_ */
