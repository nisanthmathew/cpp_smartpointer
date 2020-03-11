#include <QtTest>

// add necessary includes here

class smartpointertestcase : public QObject
{
    Q_OBJECT

public:
    smartpointertestcase();
    ~smartpointertestcase();

private slots:
    void initTestCase();
    void cleanupTestCase();

};




QTEST_APPLESS_MAIN(smartpointertestcase)

#include "tst_smartpointertestcase.moc"
