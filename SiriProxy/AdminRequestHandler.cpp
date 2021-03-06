// Copyright (c) 2011,cd-team.org.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
#include "AdminRequestHandler.h"
#include "HtmlHelper.h"
#include "SiriTcpSvr.h"
void AdminRequestHandler::handleRequest( HTTPServerRequest& request, HTTPServerResponse& response )
{
	ostream& resp=response.send();
	if(request.getMethod()!=HTTPRequest::HTTP_GET)
	{
		resp<<"非法的METHOD!";
		return;
	}
	string url=request.getURI();
	url=Poco::toLower(url);
	request.setContentType("text/html");

	string html;
	if(url==HtmlHelper::key_man_url)
	{
		html=HtmlHelper::GetKeyListHtml();
	}
	else if(url==HtmlHelper::key_trace_url)
	{
		html=HtmlHelper::GetTraceHtml();
	}
	else
	{
		html=HtmlHelper::GetHostHtmlInfo();
	}
	resp<<html;
}

void ForbiddenRequestHandler::handleRequest( HTTPServerRequest& request, HTTPServerResponse& response )
{
	ostream& resp=response.send();
	resp<<"操作禁止!没有该路径!"; 
}
