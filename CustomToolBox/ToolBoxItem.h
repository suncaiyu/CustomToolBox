#ifndef TOOLBOXITEM_H
#define TOOLBOXITEM_H
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPropertyAnimation>

class ToolBoxItemTitle :public QWidget
{
    Q_OBJECT
public:
    explicit ToolBoxItemTitle(QWidget *parent = nullptr);
    ~ToolBoxItemTitle(){};
    void SetHeight(int height) { resize(this->width(), height); }
    void SetText(const QString &t) { mTitleLabel->setText(t);}

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    void InitUi();
    bool mExpand = true;
    std::unique_ptr<QLabel> mTitleLabel;
    std::unique_ptr<QHBoxLayout> mLayout;
signals:
    void ExpandSignal(bool);
};

class ToolBoxItem : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int aniHeight READ AniHeight WRITE SetAniHeight)
public:
    explicit ToolBoxItem(QWidget *parent = nullptr);
    ~ToolBoxItem();
    void AppendWidget(QWidget *l, int itemHeight);

private:
    void InitUi();
    std::unique_ptr<ToolBoxItemTitle> mTitle;
    std::unique_ptr<QVBoxLayout> mLayout;
    std::unique_ptr<QWidget> mExpandPane;
    std::unique_ptr<QVBoxLayout> mExpandPaneLayout;
    int hhh = 0;
    int aniHeight = 0;
    void SetAniHeight(int h);
    int AniHeight();
    std::unique_ptr<QPropertyAnimation> mAni;
};

#endif // TOOLBOXITEM_H
