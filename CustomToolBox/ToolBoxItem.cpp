#include "ToolBoxItem.h"
#include <QPainter>
#include <QDebug>
ToolBoxItemTitle::ToolBoxItemTitle(QWidget *parent) : QWidget(parent)
{
    setFixedHeight(30);
    InitUi();
}

void ToolBoxItemTitle::mousePressEvent(QMouseEvent *event)
{
    mExpand = !mExpand;
    emit ExpandSignal(mExpand);
}

void ToolBoxItemTitle::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.fillRect(this->rect(), Qt::lightGray);
}

void ToolBoxItemTitle::InitUi()
{
    mLayout = std::make_unique<QHBoxLayout>(this);
    setLayout(mLayout.get());
    mTitleLabel = std::make_unique<QLabel>("Title");
    mLayout->addWidget(mTitleLabel.get());

}

ToolBoxItem::ToolBoxItem(QWidget *parent) : QWidget(parent)
{
    InitUi();
}

ToolBoxItem::~ToolBoxItem()
{

}

void ToolBoxItem::AppendWidget(QWidget *item, int itemHeight)
{
    item->setFixedHeight(itemHeight);
    mExpandPaneLayout->addWidget(item);
    hhh += itemHeight;
}

void ToolBoxItem::InitUi()
{
    mLayout = std::make_unique<QVBoxLayout>(this);
    mLayout->setSpacing(0);
    mLayout->setMargin(1);
    mTitle = std::make_unique<ToolBoxItemTitle>(this);
    mLayout->addWidget(mTitle.get());
    setLayout(mLayout.get());
    mExpandPane = std::make_unique<QWidget>();
    mLayout->addWidget(mExpandPane.get());
    mExpandPaneLayout = std::make_unique<QVBoxLayout>();
    mExpandPane->setLayout(&*mExpandPaneLayout);
    mExpandPaneLayout->setMargin(0);
    mExpandPaneLayout->setSpacing(0);
    connect(&*mTitle, &ToolBoxItemTitle::ExpandSignal, this, [this](bool f){
        if (f) {
            mAni->setStartValue(0);
            mAni->setEndValue(hhh);
            mAni->setEasingCurve(QEasingCurve::OutQuint);
        } else {
            mAni->setStartValue(hhh);
            mAni->setEndValue(0);
            mAni->setEasingCurve(QEasingCurve::InQuint);
        }
        if (mAni->state() == mAni->Running) {
            mAni->stop();

        }
        mAni->start();
    });
    mAni = std::make_unique<QPropertyAnimation>(this, "aniHeight");
    mAni->setDuration(222);
}

void ToolBoxItem::SetAniHeight(int h)
{
    mExpandPane->setFixedHeight(h);
}

int ToolBoxItem::AniHeight()
{
    return aniHeight;
}
