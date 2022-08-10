<img src="https://github.com/mw30p/verseB_pie_xtoearn_json_api-kr/blob/main/images/PiE.jpg">

* MW30P(Metaverse WEB 3.0 Blockchain Platform)은 게임 뿐만 아니라 복잡한구조의 다양한 비즈니스들을 블록체인과 편리하게 연결하여 효율적이고 미래지향적인 사업환경이 구성 가능하도록 지원하며 WEB 3.0의 통합 서비스 생태계를 제공합니다.
<br>
<img src="https://github.com/mw30p/verseB_pie_xtoearn_json_api-kr/blob/main/images/web30.jpg">
<br>
<br>

* MW30P는 블록체인의 기능의 한계와 보안 이슈, 높은 개발 난이도, 관리의 비효율성 등에 대응하기 위해 자체 개발 및 운영되어 검증된 프레임워크로 구성되어 있으며 유연한 메시지 관리와 다양한 인터페이스를 통해 편리하게 서비스를 제공 받을 수 있습니다.
<br>
<img src="https://github.com/mw30p/verseB_pie_xtoearn_json_api-kr/blob/main/images/mw30p.jpg">
<br>
<br>

* MW30P 내부 및 외부 연계, 서비스 관리, PiE (Profit in Everything) 서비스를 위한 모니터링과 통계, 보고서 등의 기능을 통해 관리의 효율을 극대화합니다
<br>
<img src="https://github.com/mw30p/verseB_pie_xtoearn_json_api-kr/blob/main/images/admin.jpg">
<br>
<br>

### MW30P X-To-Earn Interface API
API는 성능을 고려하여 Sync 타입과 Async 타입으로 분류됩니다. 제휴사는 각 API에 해당되는 기능을 적용하며 JSON, C/C++, JAVA등 다양한 개발언어를 지원합니다.

**※ 제휴/연동 테스트 및 개발 문의 : testingplanner@cholocb.com**

- JSON API SAMPLE : https://github.com/mw30p/verseB_pie_xtoearn_json_api-kr/tree/main/src
- JAVA API SAMPLE : https://github.com/mw30p/verseB_pie_xtoearn_java_api-kr/tree/main/src/main/java/com/mw30p/p2e
- C/C++ API SAMPLE : https://github.com/mw30p/verseB_pie_xtoearn_cpp_api-kr/tree/main/src

X-To-Earn and Profit in Everything
* Play to Earn (P2E)
* Move to Earn (M2E)
* Learn to Earn (L2E)
* Search to Earn (S2E)
* Watch to Earn (W2E)
* Create to Earn (C2E)
* Write to Earn (W2E)
* Buy to Earn (B2E)

| API | 요청 | 처리 | 기능 | 비고 |
|----------------------------|--------|--------|------|------|
|Exchange Rate Inquiry|Partners|MW30P|Item/Point/etc to PlayToken 환율 조회<br>PlayToken to Item/Point/etc 환율 조회<br>(파트너사가 사용자에게 제공하는 각종 혜택 등)||
|Exchange |Partners|MW30P|Item/Point/etc to PlayToken 전환<br>PlayToken to Item/Point/etc 전환|Async|
|Passport|Partners|MW30P|주요 API 실행을 위한 인증 서비스||
|Withdrawal Address|Partners|MW30P|Partner사의 사용자가 보유한 외부에서 사용할 수 있는<br>블록체인 주소에 대한 검증 및 등록/변경 (인출주소) ||
|Withdrawal pre-trade|Partners|MW30P|인출 예비 거래||
|Withdrawal|Partners|MW30P|인출 가능 토큰(PlayToken 등)을 외부 주소로 인출|Async|
|Block Notify|MW30P|Partners|Exchange API, Withdrawal API의 블록체인 처리 결과 전송<br>(Confirm 완료 여부)|Async|


