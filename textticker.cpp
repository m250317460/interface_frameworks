#include "textticker.h"
#include <QPainter>
#include <QTimer>

TextTicker::TextTicker(QWidget *parent) :QLabel (parent)
{
//    setMinimumWidth(200);
//    setMinimumHeight(30);

    m_curIndex = 0;
    m_showText = "test";
    m_charWidth = fontMetrics().width("a");

    QTimer *timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&TextTicker::updateIndex);
    timer->start(100);
}
TextTicker::~TextTicker()
{

}

void TextTicker::setText(QString text)
{
    m_showText = text;

}
void TextTicker::paintEvent(QPaintEvent *event)
{
//    super::paintEvent(event);
    QPainter painter(this);
    painter.drawText(0,20,m_showText.mid(m_curIndex));
    painter.drawText(width() - m_charWidth*m_curIndex,20,m_showText.left(m_curIndex));

}

void TextTicker::updateIndex()
{
    update();
    m_curIndex++;
    if(m_curIndex*m_charWidth>width())
        m_curIndex=0;
}
