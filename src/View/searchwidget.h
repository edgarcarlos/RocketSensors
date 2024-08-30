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

namespace View {

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
    QCheckBox* temperatura;
    QCheckBox* pressione;
    QCheckBox* carburante;
    QCheckBox* position;

signals:
    void  searchTriggered(const std::string& query);
    void filterTypesChanged(const std::vector<QString>& types);

public slots:
    void searchClicked();
    void Checkboxchanged();
};

}
#endif // SEARCHWIDGET_H
