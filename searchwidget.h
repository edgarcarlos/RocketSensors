#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QToolButton>
#include <QMenu>
#include <QCheckBox>
#include <QWidgetAction>
#include <QPushButton>

class SearchWidget: public QWidget
{
    Q_OBJECT
public:
    explicit SearchWidget(QWidget *parent = nullptr);

private:
    QHBoxLayout* layout;
    QFormLayout* formLayout;
    QLineEdit* searchInput;
    QToolButton* filterButton;
    QMenu* filterMenu;

signals:
    void  searchTriggered(const QString &searchString);

public slots:
    void search();
    void Checkboxchanged();
};

#endif // SEARCHWIDGET_H
