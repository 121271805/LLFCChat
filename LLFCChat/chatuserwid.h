﻿#ifndef CHATUSERWID_H
#define CHATUSERWID_H

#include "listitembase.h"
#include "userdata.h"
/******************************************************************************
 *
 * @file       chatuserwid.h
 * @brief      单个聊天用户item
 *
 * @author     Carpe_Diem
 * @date       2024/12/04
 * @history
 *****************************************************************************/
namespace Ui {
class ChatUserWid;
}

class ChatUserWid : public ListItemBase
{
    Q_OBJECT

public:
    explicit ChatUserWid(QWidget *parent = nullptr);
    ~ChatUserWid();

    QSize sizeHint() const override {
        return QSize(250, 70);//返回自定义尺寸
    }

	void SetInfo(std::shared_ptr<UserInfo> user_info);
	std::shared_ptr<UserInfo> GetUserInfo();

private:
    Ui::ChatUserWid *ui;
    std::shared_ptr<UserInfo> _user_info;
};

#endif // CHATUSERWID_H
