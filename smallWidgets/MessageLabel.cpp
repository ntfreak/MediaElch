#include "MessageLabel.h"

MessageLabel::MessageLabel(QWidget *parent, int alignment) :
    QLabel(parent)
{
    setAlignment(static_cast<Qt::Alignment>(alignment));
}

void MessageLabel::setErrorMessage(const QString &text)
{
    setStyleSheet("color: #B94A48;");
    setText(text);
}

void MessageLabel::setSuccessMessage(const QString &text)
{
    setStyleSheet("color: #468847;");
    setText(text);
}

void MessageLabel::clear()
{
    setText(" ");
}
