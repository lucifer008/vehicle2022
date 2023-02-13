#ifndef FORMEMBED_H
#define FORMEMBED_H

#include <QWidget>

namespace Ui {
class FormEmbed;
}

class FormEmbed : public QWidget
{
    Q_OBJECT

public:
    explicit FormEmbed(QWidget *parent = nullptr);
    ~FormEmbed();

private:
    Ui::FormEmbed *ui;
};

#endif // FORMEMBED_H
