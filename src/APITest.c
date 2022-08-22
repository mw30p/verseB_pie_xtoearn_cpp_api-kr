/*
 * APITest.c
 *
 *  Created on: 2022. 7. 11.
 *      Author: NextBankDev
 */

#include <stdio.h>
#include <string.h>
#include <VerseB.h>

int main(int argc, char *args[])
{
	if (argc != 3){
		printf("[Usage] %s [API] [exRate|passportRegister|passportChange|exReq|WithdrawalAddress|WithdrawReq]\n", args[0]);
		return -1;
	}

	// Test 설정
	iMode									= 0;
	// Real 설정
	//iMode									= 1;
	char*				mctKey				= "9F2488BFAE5FB03B9B483FA1CF1EC94B3B4B2E52780A2B53ED67E581110CC980";
	char*				mctInitialVector	= "64750805549512089392625993734535";
	char*				mctNotifyUrl		= "http://10.30.1.51:8180/p2e/AsyncResult.jsp";
	int					iRet				= 0;

	if (strcmp("API",args[1]) == 0) {
		// exRate
		if (strcmp("exRate", args[2]) == 0) {
			exRate_IN	exRateIn;
			exRate_OUT	exRateOut;

			strncpy(exRateIn.merchantId,		"000000000001",		sizeof(exRateIn.merchantId));
			strncpy(exRateIn.merchantSiteId,	"000001",			sizeof(exRateIn.merchantSiteId));
			strncpy(exRateIn.customerId,		"000000000001",		sizeof(exRateIn.customerId));
			strncpy(exRateIn.fromCurrency,		"GOLD",				sizeof(exRateIn.fromCurrency));
			strncpy(exRateIn.toCurrency,		"SLAYB",			sizeof(exRateIn.toCurrency));
			strncpy(exRateIn.fromAmount,		"100",				sizeof(exRateIn.fromAmount));
			strncpy(exRateIn.key,				mctKey,				sizeof(exRateIn.key));
			strncpy(exRateIn.initialVector,		mctInitialVector,	sizeof(exRateIn.initialVector));

			iRet	= exRate(&exRateIn, &exRateOut);

			printf("API exRate ret=%d\n\tmerchantId=%s\n\tmerchantSiteId=%s\n\tcode=%s\n\tcustomerId=%s\n"
					"\tfromCurrency=%s\n\ttoCurrency=%s\n\tfromAmount=%s\n\ttoAmount=%s\n\texchangeRate=%s\n"
					"\tstatus=%s\n\terrCd=%s\n\treason=%s\n",
					iRet, exRateOut.merchantId, exRateOut.merchantSiteId, exRateOut.code, exRateOut.customerId,
					exRateOut.fromCurrency, exRateOut.toCurrency, exRateOut.fromAmount, exRateOut.toAmount, exRateOut.exchangeRate,
					exRateOut.status, exRateOut.errCd, exRateOut.reason);
		}
		// passportRegister
		else if (strcmp("passportRegister", args[2]) == 0) {
			pass_IN		passIn;
			pass_OUT	passOut;

			strncpy(passIn.merchantId,			"000000000001",		sizeof(passIn.merchantId));
			strncpy(passIn.merchantSiteId,		"000001",			sizeof(passIn.merchantSiteId));
			strncpy(passIn.customerId,			"000000000001",		sizeof(passIn.customerId));
			strncpy(passIn.PassportOption,		"Register",			sizeof(passIn.PassportOption));
			strncpy(passIn.newPassword,			"12345678",			sizeof(passIn.newPassword));
			strncpy(passIn.key,					mctKey,				sizeof(passIn.key));
			strncpy(passIn.initialVector,		mctInitialVector,	sizeof(passIn.initialVector));

			iRet	= Passport(&passIn, &passOut);

			printf("API passportRegister ret=%d\n\tmerchantId=%s\n\tmerchantSiteId=%s\n\tcode=%s\n\tcustomerId=%s\n"
					"\tPapers=%s\n"
					"\tstatus=%s\n\terrCd=%s\n\treason=%s\n",
					iRet, passOut.merchantId, passOut.merchantSiteId, passOut.code, passOut.customerId,
					passOut.Papers,
					passOut.status, passOut.errCd, passOut.reason);
		}
		// passportChange
		else if (strcmp("passportChange", args[2]) == 0) {
			pass_IN		passIn;
			pass_OUT	passOut;

			strncpy(passIn.merchantId,			"000000000001",		sizeof(passIn.merchantId));
			strncpy(passIn.merchantSiteId,		"000001",			sizeof(passIn.merchantSiteId));
			strncpy(passIn.customerId,			"000000000001",		sizeof(passIn.customerId));
			strncpy(passIn.PassportOption,		"Certify",			sizeof(passIn.PassportOption));
			strncpy(passIn.outPassword,			"12345678",			sizeof(passIn.outPassword));
			strncpy(passIn.key,					mctKey,				sizeof(passIn.key));
			strncpy(passIn.initialVector,		mctInitialVector,	sizeof(passIn.initialVector));

			iRet	= Passport(&passIn, &passOut);

			printf("API passportCertify ret=%d\n\tmerchantId=%s\n\tmerchantSiteId=%s\n\tcode=%s\n\tcustomerId=%s\n"
					"\tPapers=%s\n"
					"\tstatus=%s\n\terrCd=%s\n\treason=%s\n",
					iRet, passOut.merchantId, passOut.merchantSiteId, passOut.code, passOut.customerId,
					passOut.Papers,
					passOut.status, passOut.errCd, passOut.reason);

			if (strcmp("SUCCESS", passOut.status) == 0) {
				pass_IN		passIn2;
				pass_OUT	passOut2;

				strncpy(passIn2.merchantId,			"000000000001",		sizeof(passIn2.merchantId));
				strncpy(passIn2.merchantSiteId,		"000001",			sizeof(passIn2.merchantSiteId));
				strncpy(passIn2.customerId,			"000000000001",		sizeof(passIn2.customerId));
				strncpy(passIn2.PassportOption,		"Change",			sizeof(passIn2.PassportOption));
				strncpy(passIn2.outPassword,		"12345678",			sizeof(passIn2.outPassword));
				strncpy(passIn2.newPassword,		"12345678",			sizeof(passIn2.newPassword));
				strncpy(passIn2.Papers,				passOut.Papers,		sizeof(passIn2.Papers));
				strncpy(passIn2.key,				mctKey,				sizeof(passIn2.key));
				strncpy(passIn2.initialVector,		mctInitialVector,	sizeof(passIn2.initialVector));

				iRet	= Passport(&passIn2, &passOut2);

				printf("API passportCertify ret=%d\n\tmerchantId=%s\n\tmerchantSiteId=%s\n\tcode=%s\n\tcustomerId=%s\n"
						"\tPapers=%s\n"
						"\tstatus=%s\n\terrCd=%s\n\treason=%s\n",
						iRet, passOut2.merchantId, passOut2.merchantSiteId, passOut2.code, passOut2.customerId,
						passOut2.Papers,
						passOut2.status, passOut2.errCd, passOut2.reason);
			}
		}
		// exReq
		else if (strcmp("exReq", args[2]) == 0) {
			pass_IN		passIn;
			pass_OUT	passOut;

			strncpy(passIn.merchantId,			"000000000001",		sizeof(passIn.merchantId));
			strncpy(passIn.merchantSiteId,		"000001",			sizeof(passIn.merchantSiteId));
			strncpy(passIn.customerId,			"000000000001",		sizeof(passIn.customerId));
			strncpy(passIn.PassportOption,		"Certify",			sizeof(passIn.PassportOption));
			strncpy(passIn.outPassword,			"12345678",			sizeof(passIn.outPassword));
			strncpy(passIn.key,					mctKey,				sizeof(passIn.key));
			strncpy(passIn.initialVector,		mctInitialVector,	sizeof(passIn.initialVector));

			iRet	= Passport(&passIn, &passOut);

			printf("API passportCertify ret=%d\n\tmerchantId=%s\n\tmerchantSiteId=%s\n\tcode=%s\n\tcustomerId=%s\n"
					"\tPapers=%s\n"
					"\tstatus=%s\n\terrCd=%s\n\treason=%s\n",
					iRet, passOut.merchantId, passOut.merchantSiteId, passOut.code, passOut.customerId,
					passOut.Papers,
					passOut.status, passOut.errCd, passOut.reason);

			if (strcmp("SUCCESS", passOut.status) == 0) {
				exReq_IN	exReqIn;
				exReq_OUT	exReqOut;

				strncpy(exReqIn.merchantId,			"000000000001",		sizeof(exReqIn.merchantId));
				strncpy(exReqIn.merchantSiteId,		"000001",			sizeof(exReqIn.merchantSiteId));
				strncpy(exReqIn.customerId,			"000000000001",		sizeof(exReqIn.customerId));
				strncpy(exReqIn.fromCurrency,		"GOLD",				sizeof(exReqIn.fromCurrency));
				strncpy(exReqIn.toCurrency,			"SLAYB",			sizeof(exReqIn.toCurrency));
				strncpy(exReqIn.fromAmount,			"100",				sizeof(exReqIn.fromAmount));
				strncpy(exReqIn.exchangeRate,		"10%",				sizeof(exReqIn.exchangeRate));
				strncpy(exReqIn.outPassword,		"12345678",			sizeof(exReqIn.outPassword));
				strncpy(exReqIn.Papers,				passOut.Papers,		sizeof(exReqIn.Papers));
				strncpy(exReqIn.notifyUrl,			mctNotifyUrl,		sizeof(exReqIn.notifyUrl));
				strncpy(exReqIn.key,				mctKey,				sizeof(exReqIn.key));
				strncpy(exReqIn.initialVector,		mctInitialVector,	sizeof(exReqIn.initialVector));

				iRet	= exReq(&exReqIn, &exReqOut);

				printf("API exReq ret=%d\n\tmerchantId=%s\n\tmerchantSiteId=%s\n\tcode=%s\n\tcustomerId=%s\n"
						"\tfromCurrency=%s\n\ttoCurrency=%s\n\tfromAmount=%s\n\ttoAmount=%s\n\texchangeRate=%s\n"
						"\tinternalAddress=%s\n\ttxId=%s\n"
						"\tstatus=%s\n\terrCd=%s\n\treason=%s\n",
						iRet, exReqOut.merchantId, exReqOut.merchantSiteId, exReqOut.code, exReqOut.customerId,
						exReqOut.fromCurrency, exReqOut.toCurrency, exReqOut.fromAmount, exReqOut.toAmount, exReqOut.exchangeRate,
						exReqOut.internalAddress, exReqOut.txId,
						exReqOut.status, exReqOut.errCd, exReqOut.reason);
			}
		}
		// WithdrawalAddress
		else if (strcmp("WithdrawalAddress", args[2]) == 0) {
			pass_IN		passIn;
			pass_OUT	passOut;

			strncpy(passIn.merchantId,			"000000000001",		sizeof(passIn.merchantId));
			strncpy(passIn.merchantSiteId,		"000001",			sizeof(passIn.merchantSiteId));
			strncpy(passIn.customerId,			"000000000001",		sizeof(passIn.customerId));
			strncpy(passIn.PassportOption,		"Certify",			sizeof(passIn.PassportOption));
			strncpy(passIn.outPassword,			"12345678",			sizeof(passIn.outPassword));
			strncpy(passIn.key,					mctKey,				sizeof(passIn.key));
			strncpy(passIn.initialVector,		mctInitialVector,	sizeof(passIn.initialVector));

			iRet	= Passport(&passIn, &passOut);

			printf("API passportCertify ret=%d\n\tmerchantId=%s\n\tmerchantSiteId=%s\n\tcode=%s\n\tcustomerId=%s\n"
					"\tPapers=%s\n"
					"\tstatus=%s\n\terrCd=%s\n\treason=%s\n",
					iRet, passOut.merchantId, passOut.merchantSiteId, passOut.code, passOut.customerId,
					passOut.Papers,
					passOut.status, passOut.errCd, passOut.reason);

			if (strcmp("SUCCESS", passOut.status) == 0) {
				outAddr_IN	outAddrIn;
				outAddr_OUT	outAddrOut;

				strncpy(outAddrIn.merchantId,		"000000000001",		sizeof(outAddrIn.merchantId));
				strncpy(outAddrIn.merchantSiteId,	"000001",			sizeof(outAddrIn.merchantSiteId));
				strncpy(outAddrIn.customerId,		"000000000001",		sizeof(outAddrIn.customerId));
				strncpy(outAddrIn.outAddress,		"0x8bDfa1f6393146f005F1C84050c553367c1e27d2",				sizeof(outAddrIn.outAddress));
				strncpy(outAddrIn.outPassword,		"12345678",			sizeof(outAddrIn.outPassword));
				strncpy(outAddrIn.Papers,			passOut.Papers,		sizeof(outAddrIn.Papers));
				strncpy(outAddrIn.key,				mctKey,				sizeof(outAddrIn.key));
				strncpy(outAddrIn.initialVector,	mctInitialVector,	sizeof(outAddrIn.initialVector));

				iRet	= outAddr(&outAddrIn, &outAddrOut);

				printf("API WithdrawalAddress ret=%d\n\tmerchantId=%s\n\tmerchantSiteId=%s\n\tcode=%s\n\tcustomerId=%s\n"
						"\toutAddress=%s\n"
						"\tstatus=%s\n\terrCd=%s\n\treason=%s\n",
						iRet, outAddrOut.merchantId, outAddrOut.merchantSiteId, outAddrOut.code, outAddrOut.customerId,
						outAddrOut.outAddress,
						outAddrOut.status, outAddrOut.errCd, outAddrOut.reason);
			}
		}
		// WithdrawReq
		else if (strcmp("WithdrawReq", args[2]) == 0) {
			preTrade_IN		preTradeIn;
			preTrade_OUT	preTradeOut;

			strncpy(preTradeIn.merchantId,		"000000000001",		sizeof(preTradeIn.merchantId));
			strncpy(preTradeIn.merchantSiteId,	"000001",			sizeof(preTradeIn.merchantSiteId));
			strncpy(preTradeIn.customerId,		"000000000001",		sizeof(preTradeIn.customerId));
			strncpy(preTradeIn.fromCurrency,	"SLAYB",			sizeof(preTradeIn.fromCurrency));
			strncpy(preTradeIn.toCurrency,		"SLAYB",			sizeof(preTradeIn.toCurrency));
			strncpy(preTradeIn.fromAmount,		"10",				sizeof(preTradeIn.fromAmount));
			strncpy(preTradeIn.key,				mctKey,				sizeof(preTradeIn.key));
			strncpy(preTradeIn.initialVector,	mctInitialVector,	sizeof(preTradeIn.initialVector));

			iRet		= reqPreTrade(&preTradeIn, &preTradeOut);

			printf("API reqWithdraw ret=%d\n\tmerchantId=%s\n\tmerchantSiteId=%s\n\tcode=%s\n\tcustomerId=%s\n"
					"\toutAddress=%s\n"
					"\tfromCurrency=%s\n\ttoCurrency=%s\n\tfromAmount=%s\n\twithdrawalRate=%s\n\ttoAmount=%s\n"
					"\twithdrawalFee=%s\n\twithdrawalAmount=%s\n\tReserveWID=%s\n\tpinNumber=%s\n"
					"\tstatus=%s\n\terrCd=%s\n\treason=%s\n",
					iRet, preTradeOut.merchantId, preTradeOut.merchantSiteId, preTradeOut.code, preTradeOut.customerId,
					preTradeOut.outAddress,
					preTradeOut.fromCurrency, preTradeOut.toCurrency, preTradeOut.fromAmount, preTradeOut.withdrawalRate, preTradeOut.toAmount,
					preTradeOut.withdrawalFee, preTradeOut.withdrawalAmount, preTradeOut.ReserveWID, preTradeOut.pinNumber,
					preTradeOut.status, preTradeOut.errCd, preTradeOut.reason);

			if (strcmp("SUCCESS", preTradeOut.status) == 0) {
				pass_IN		passIn;
				pass_OUT	passOut;

				strncpy(passIn.merchantId,			"000000000001",		sizeof(passIn.merchantId));
				strncpy(passIn.merchantSiteId,		"000001",			sizeof(passIn.merchantSiteId));
				strncpy(passIn.customerId,			"000000000001",		sizeof(passIn.customerId));
				strncpy(passIn.PassportOption,		"Certify",			sizeof(passIn.PassportOption));
				strncpy(passIn.outPassword,			"12345678",			sizeof(passIn.outPassword));
				strncpy(passIn.key,					mctKey,				sizeof(passIn.key));
				strncpy(passIn.initialVector,		mctInitialVector,	sizeof(passIn.initialVector));

				iRet	= Passport(&passIn, &passOut);

				printf("API passportCertify ret=%d\n\tmerchantId=%s\n\tmerchantSiteId=%s\n\tcode=%s\n\tcustomerId=%s\n"
						"\tPapers=%s\n"
						"\tstatus=%s\n\terrCd=%s\n\treason=%s\n",
						iRet, passOut.merchantId, passOut.merchantSiteId, passOut.code, passOut.customerId,
						passOut.Papers,
						passOut.status, passOut.errCd, passOut.reason);

				if (strcmp("SUCCESS", passOut.status) == 0) {
					reqWdraw_IN		reqWdrawIn;
					reqWdraw_OUT	reqWdrawOut;

					strncpy(reqWdrawIn.merchantId,		"000000000001",					sizeof(reqWdrawIn.merchantId));
					strncpy(reqWdrawIn.merchantSiteId,	"000001",						sizeof(reqWdrawIn.merchantSiteId));
					strncpy(reqWdrawIn.customerId,		"000000000001",					sizeof(reqWdrawIn.customerId));
					strncpy(reqWdrawIn.outAddress,		preTradeOut.outAddress,			sizeof(reqWdrawIn.outAddress));
					strncpy(reqWdrawIn.fromCurrency,	preTradeOut.fromCurrency	,	sizeof(reqWdrawIn.fromCurrency));
					strncpy(reqWdrawIn.toCurrency,		preTradeOut.toCurrency,			sizeof(reqWdrawIn.toCurrency));
					strncpy(reqWdrawIn.fromAmount,		preTradeOut.fromAmount,			sizeof(reqWdrawIn.fromAmount));
					strncpy(reqWdrawIn.withdrawalRate,	preTradeOut.withdrawalRate,		sizeof(reqWdrawIn.withdrawalRate));
					strncpy(reqWdrawIn.toAmount,		preTradeOut.toAmount,			sizeof(reqWdrawIn.toAmount));
					strncpy(reqWdrawIn.withdrawalFee,	preTradeOut.withdrawalFee,		sizeof(reqWdrawIn.withdrawalFee));
					strncpy(reqWdrawIn.withdrawalAmount,preTradeOut.withdrawalAmount,	sizeof(reqWdrawIn.withdrawalAmount));
					strncpy(reqWdrawIn.ReserveWID,		preTradeOut.ReserveWID,			sizeof(reqWdrawIn.ReserveWID));
					strncpy(reqWdrawIn.pinNumber,		preTradeOut.pinNumber,			sizeof(reqWdrawIn.pinNumber));
					strncpy(reqWdrawIn.outPassword,		"12345678",						sizeof(reqWdrawIn.outPassword));
					strncpy(reqWdrawIn.Papers,			passOut.Papers,					sizeof(reqWdrawIn.Papers));
					strncpy(reqWdrawIn.notifyUrl,		mctNotifyUrl,					sizeof(reqWdrawIn.notifyUrl));
					strncpy(reqWdrawIn.key,				mctKey,							sizeof(reqWdrawIn.key));
					strncpy(reqWdrawIn.initialVector,	mctInitialVector,				sizeof(reqWdrawIn.initialVector));

					iRet	= reqWithdraw(&reqWdrawIn, &reqWdrawOut);

					printf("API reqWithdraw ret=%d\n\tmerchantId=%s\n\tmerchantSiteId=%s\n\tcode=%s\n\tcustomerId=%s\n"
							"\toutAddress=%s\n"
							"\tfromCurrency=%s\n\ttoCurrency=%s\n\tfromAmount=%s\n\twithdrawalRate=%s\n\ttoAmount=%s\n"
							"\ttxId=%s\n\ttxId=%s\n\ttxId=%s\n"
							"\tstatus=%s\n\terrCd=%s\n\treason=%s\n",
							iRet, reqWdrawOut.merchantId, reqWdrawOut.merchantSiteId, reqWdrawOut.code, reqWdrawOut.customerId,
							reqWdrawOut.outAddress,
							reqWdrawOut.fromCurrency, reqWdrawOut.toCurrency, reqWdrawOut.fromAmount, reqWdrawOut.withdrawalRate, reqWdrawOut.toAmount,
							reqWdrawOut.withdrawalFee, reqWdrawOut.withdrawalAmount, reqWdrawOut.txId,
							reqWdrawOut.status, reqWdrawOut.errCd, reqWdrawOut.reason);
				}
			}
		}
	}

	return 0;
}

