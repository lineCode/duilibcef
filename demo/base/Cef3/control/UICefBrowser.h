#pragma once

#include <queue>

#include "include/cef_client.h"

#include "../common/process_message_handler.h"
#include "../common/cef_client_handler.h"

using CefCacheTask = std::function<void(void)>;

class CCefBrowserUI : public CControlUI
{
public:
	CCefBrowserUI();
	virtual ~CCefBrowserUI();

	// Control
	virtual void DoInit() override;
	virtual void DoPaint(HDC hDC, const RECT& rcPaint) override;
	virtual void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue) override;
	virtual void SetVisible(bool bVisible) override;
	virtual void SetInternVisible(bool bVisible) override;


	// CefClientHandler�ص��ӿ�
	void OnProcessMessageReceived(CefRefPtr<CefProcessMessage> message);
	void OnAfterCreated(CefRefPtr<CefBrowser> browser);


	// �Զ���ӿ�
	void Navigate2(CefString url);
	void RunJs(CefString JsCode);


	// ������Ϣ����
	void SetProcessMessageHandler(CefRefPtr<CProcessMessageHandler> pHandler);

private:
	void resize();

private:
	
	CefRefPtr<CCefClientHandler>		m_pClientHandler;
	CefRefPtr<CefBrowser>				m_pBrowser;
	CefRefPtr<CProcessMessageHandler>	m_pProcessMessageHandler;

	// browser�������ǰ���������
	std::queue<CefCacheTask>	m_AfterCreatedCacheTasks;
};