#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <QObject>

class Ingredient : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString type READ type WRITE setType NOTIFY typeChanged)

private:

    QString m_name;
    QString m_type;

public:

    Ingredient(QString ingredientName, QString ingredientType);

    QString name() const;
    QString type() const;

public slots:

    void setName(QString name);
    void setType(QString type);

signals:

    void nameChanged(QString name);
    void typeChanged(QString type);
};


#endif // INGREDIENT_H
