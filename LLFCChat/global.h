﻿#ifndef GLOBAL_H
#define GLOBAL_H

#include <QWidget>
#include <functional>
#include "QStyle"
#include <QRegularExpression>
#include <memory>
#include <iostream>
#include <mutex>
#include <QByteArray>
#include <QNetworkReply>
#include <QJsonObject>
#include <QStringConverter>
#include <QDir>
#include <QSettings>
/******************************************************************************
 *
 * @file       global.h
 * @brief      全局变量
 *
 * @author     Carpe_Diem
 * @date       2024/12/04
 * @history
 *****************************************************************************/
/**
 * @brief repolish 用于刷新qss
 */
extern std::function<void(QWidget*)> repolish;

/**
 * 异或字符串，用于密码存储时加密
 */
extern std::function<QString(QString)> xorString;

enum RegId{
    ID_GET_VERIFY_CODE = 1001,//验证码功能id
    ID_REG_USER = 1002,//注册用户功能id
	ID_RESET_PWD = 1003,//重置密码
	ID_LOGIN_USER = 1004,//用户登录
	ID_CHAT_LOGIN = 1005,//登陆聊天服务器
	ID_CHAT_LOGIN_RSP = 1006,//登录聊天服务器回包
	ID_SEARCH_USER_REQ = 1007, //用户搜索请求
	ID_SEARCH_USER_RSP = 1008, //搜索用户回包
	ID_ADD_FRIEND_REQ = 1009,  //添加好友申请
	ID_ADD_FRIEND_RSP = 1010, //申请添加好友回复
	ID_NOTIFY_ADD_FRIEND_REQ = 1011,  //通知用户添加好友申请
	ID_AUTH_FRIEND_REQ = 1013,  //认证好友请求
	ID_AUTH_FRIEND_RSP = 1014,  //认证好友回复
	ID_NOTIFY_AUTH_FRIEND_REQ = 1015, //通知用户认证好友申请
	ID_TEXT_CHAT_MSG_REQ = 1017,  //文本聊天信息请求
	ID_TEXT_CHAT_MSG_RSP = 1018,  //文本聊天信息回复
	ID_NOTIFY_TEXT_CHAT_MSG_REQ = 1019, //通知用户文本聊天信息
};

enum Modules {
	REGISTERMOD = 0,//注册模块
	RESETMOD = 1,//重置模块
	LOGINMOD = 2,//登录模块
};

//注册输入内容错误码
enum TipErr {
	TIP_SUCCESS = 0,
	TIP_EMAIL_ERR = 1,
	TIP_PWD_ERR = 2,
	TIP_CONFIRM_ERR = 3,
	TIP_PWD_CONFIRM = 4,
	TIP_VARIFY_ERR = 5,
	TIP_USER_ERR = 6
};

//错误码
enum ErrorCodes{
    SUCCESS = 0,//成功
    ERR_JSON = 1,//json解析失败
    ERR_NETWORK = 2,//网络错误
};

//鼠标状态
enum ClickLbState {
	Normal = 0,//普通状态
	Selected = 1//选中状态
};

extern QString gate_url_prefix;

struct ServerInfo {
	QString Host;
	QString Port;
	QString Token;
	int Uid;
};

//聊天界面几种模式
enum ChatUIMode {
	SearchMode, //搜索模式
	ChatMode, //聊天模式
	ContactMode, //联系人模式
};

//自定义QListWidgetItem的几种类型
enum ListItemType {
	CHAT_USER_ITEM, //聊天用户
	CONTACT_USER_ITEM, //联系人用户
	SEARCH_USER_ITEM, //搜索到的用户
	ADD_USER_TIP_ITEM, //提示添加用户
	INVALID_ITEM,  //不可点击条目
	GROUP_TIP_ITEM, //分组提示条目
	LINE_ITEM,  //分割线
	APPLY_FRIEND_ITEM, //好友申请
};

//聊天角色
enum class ChatRole {
	Self,//自己
	Other//他人
};

//聊天消息类型
struct MsgInfo {
	QString msgFlag;//"text,image,file"
	QString content;//表示文件和图像的url,文本信息
	QPixmap pixmap;//文件和图片的缩略图
};

//申请好友标签输入框最低长度
const int MIN_APPLY_LABEL_ED_LEN = 40;

const QString add_prefix = "添加标签 ";

const int  tip_offset = 5;

const std::vector<QString>  strs = { "hello world !",
							 "nice to meet u",
							 "New year，new life",
							"You have to love yourself",
							"My love is written in the wind ever since the whole world is you" };

const std::vector<QString> heads = {
	":/res/head_1.jpg",
	":/res/head_2.jpg",
	":/res/head_3.jpg",
	":/res/head_4.jpg",
	":/res/head_5.jpg"
};

const std::vector<QString> names = {
	"HanMeiMei",
	"Lily",
	"Ben",
	"Androw",
	"Max",
	"Summer",
	"Candy",
	"Hunter"
};

#endif // GLOBAL_H
