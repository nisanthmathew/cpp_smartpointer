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
    void test_case1();

};

smartpointertestcase::smartpointertestcase()
{

}

smartpointertestcase::~smartpointertestcase()
{

}

void smartpointertestcase::initTestCase()
{

}

void smartpointertestcase::cleanupTestCase()
{

}

void smartpointertestcase::test_case1()
{

}

QTEST_APPLESS_MAIN(smartpointertestcase)

#include "tst_smartpointertestcase.moc"
