# roomie_rms Module

## 1. 개요

### 1.1 목표
- 로봇 컨트롤러(RC)와 ROS2 통신을 통한 실시간 제어
- PyQt6 기반 데스크톱 GUI와 이중 통신 방식 제공:
  - **HTTP API**: 동기식 데이터 요청/응답 (설정, 조회, 명령)
  - **WebSocket**: 비동기식 실시간 이벤트 (상태, 알림, 스트리밍)
- MySQL 데이터베이스를 통한 데이터 관리 및 로그 저장
- 메인 서버를 통한 로봇 관리 시스템

### 1.2 주요 기능
- **ROS2 통신**: 로봇 컨트롤러와의 실시간 명령/상태 교환
- **이중 통신 방식**:
  - **HTTP API**: RESTful 방식의 동기식 데이터 처리
  - **WebSocket**: 실시간 이벤트 스트리밍
- **데이터베이스 연동**: 로봇, 작업, 위치, 주문 정보 관리
- **통합 데이터 관리**: 동기/비동기 데이터 흐름 통합 관리

## 2. 시스템 아키텍처

```
┌─────────────────┐   HTTP API       ┌─────────────────┐    ROS2      ┌─────────────────┐
│  Desktop GUI    │ ◄──────────────► │   RMS Node      │ ◄──────────► │ Robot Controller│
│   (PyQt6)       │                  │  (Hybrid)       │              │  (ROS2)         │
│                 │   WebSocket      │                 │              │                 │
│                 │ ◄──────────────► │ ┌─────────────┐ │              │                 │
└─────────────────┘                  │ │ FastAPI     │ │              └─────────────────┘
                                     │ │ Server      │ │
                                     │ └─────────────┘ │
                                     │ ┌─────────────┐ │
                                     │ │ ROS2 Node   │ │
                                     │ │ (rclpy)     │ │
                                     │ └─────────────┘ │
                                     └─────────────────┘
                                             │
                                             │ SQL  
                                             ▼
                                     ┌─────────────────┐
                                     │   MySQL DB      │
                                     └─────────────────┘
```

🔄 데이터 흐름:
- GUI → HTTP → RMS Node (FastAPI) → 내부 처리 → RMS Node (ROS2) → Topics → Robot Controller
- Robot Controller → Topics → RMS Node (ROS2) → 내부 처리 → RMS Node (FastAPI) → WebSocket → GUI

## 3. 기술 스택

### 3.1 메인 서버 (Backend)
- **언어**: Python 3.12
- **웹 프레임워크**: FastAPI (HTTP + WebSocket 통합 지원)
- **ASGI 서버**: uvicorn
- **비동기 처리**: asyncio
- **ROS2 클라이언트**: rclpy
- **데이터베이스**: MySQL 8.0 + mysql-connector-python

### 3.2 GUI 애플리케이션 (Frontend)
- **언어**: Python 3.12
- **GUI 프레임워크**: PyQt6
- **HTTP 클라이언트**: QNetworkAccessManager
- **WebSocket 클라이언트**: QWebSocket

### 3.3 로봇 컨트롤러
- **ROS2 Distribution**: Jazzy Jalopy
- **통신 방식**: Topics, Services, Actions

## 4. 시스템 구성 요소

### 4.1 Roomie Main Server(RMS) 모듈
```
roomie_rms/
└── roomie_rms/
    ├── __init__.py
    ├── rms_node.py         # ROS2 Node 진입점
    └── app/                # FastAPI Server
        ├── __init__.py
        ├── main.py         # FastAPI 앱 생성 및 라우터 포함
        ├── config.py       # 설정 관리
        ├── routers/        # API 엔드포인트 정의
        │   ├── __init__.py
        │   ├── rc_router.py    # 로봇 컨트롤러 API
        │   └── gui_router.py   # GUI 클라이언트 API
        │
        ├── services/       # 비즈니스 로직
        │   ├── __init__.py
        │   ├── websocket_manager.py  # WebSocket 관리자
        │   └── db_manager.py         # 데이터베이스 관리자
        │
        ├── schemas/        # 데이터 모델 (Pydantic)
        │   ├── __init__.py
        │   ├── rc_models.py    # 로봇 컨트롤러 데이터 모델 (ROS2 msgs 구조)
        │   └── gui_models.py   # GUI 데이터 모델 (요청-응답 json 구조)
        │
        └── utils/          # 기타 유틸리티
            ├── __init__.py
            └── logger.py
```

