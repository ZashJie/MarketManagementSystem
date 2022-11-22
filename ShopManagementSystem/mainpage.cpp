#include "mainpage.h"
#include "ui_mainpage.h"
#include "signin_page.h"
//#include <QDebug>

mainpage::mainpage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainpage)
{
    ui->setupUi(this);

    // 连接数据库
    this->mydatabase.getConnection();

    // 为表格模式指针指定内存
    this->dataTableModel = new QStandardItemModel();

    // 设置表格
    // this->setuinfoTableInfo();

    ui->stackedWidget->setCurrentIndex(0);
}

mainpage::~mainpage()
{
    delete ui;
}

void mainpage::setuinfoTableInfo()
{
    // 设置表头
    this->dataTableModel->setHorizontalHeaderItem(0, new QStandardItem("用户名"));
    this->dataTableModel->setHorizontalHeaderItem(1, new QStandardItem("用户密码"));
    this->dataTableModel->setHorizontalHeaderItem(2, new QStandardItem("用户姓名"));

    // 设置表格信息
    // this->getDatabaseInfo();

    // 设置列宽
    ui->shopTable->setColumnWidth(0, 200);
    ui->shopTable->setColumnWidth(1, 200);

    // 设置表格只读属性
    ui->shopTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // 最后将设计化的表格，装载在表格上
    ui->shopTable->setModel(this->dataTableModel);
}

/*
void mainpage::getDatabaseInfo()
{
    // 这个好像没啥用了
    qDebug() << "已进入获取商品界面!!!!!!!!!!!!!!!";
    // 第一步，从数据库中获取信息
    QSqlQuery sql;
    sql.prepare("select * from goods");
    sql.exec();

    int row = 0;        // 定义变量row表示表格行数
    while (sql.next())
    {
        this->dataTableModel->setItem(row, 0, new QStandardItem(sql.value("信息").toString()));

    }
}
*/
void mainpage::on_umaction_triggered()
{
    qDebug() << "已进入管理员用户管理界面";
    QSqlQuery sql;
    sql.prepare("select * from m_info");
    sql.exec();

    this->dataTableModel->clear();
    this->setuinfoTableInfo();

    int row = 0;        // 定义变量row表示表格行数


    while (sql.next())
    {
        this->dataTableModel->setItem(row, 0, new QStandardItem(sql.value("usernumber").toString()));
        this->dataTableModel->setItem(row, 1, new QStandardItem(sql.value("userpassword").toString()));
        this->dataTableModel->setItem(row, 2, new QStandardItem(sql.value("username").toString()));
        row++;
    }
    sql.clear();
}

// 工具栏中修改密码界面
void mainpage::on_actionmima_triggered()
{
    // 逻辑：点击进入修改密码，界面不变，然后改变下方的层级窗口，通过文本框输入，到对应sql的update语句，更新表内容
    ui->stackedWidget->setCurrentIndex(1);
}

// 工具栏中重新登录
void mainpage::on_actiondenglu_triggered()
{
    this->~mainpage();
    SignIn_Page* w = new SignIn_Page();
    w->show();
}

// stackedWidget中下标为1的界面这种的“修改”按钮
void mainpage::on_pushButton1_submit_clicked()
{
    QString number = ui->lineEdit1_account->text();
    QString name = ui->lineEdit1_name->text();
    QString firstp = ui->lineEdit1_first->text();
    QString nextp = ui->lineEdit1_next->text();

    qDebug() << number;
    qDebug() << name;
    qDebug() << firstp;
    qDebug() << nextp;

    QSqlQuery sql;

    sql.prepare("update m_info set userpassword =:nextp, username =:name where usernumber =:number AND userpassword =:firstp");

    sql.bindValue(":number", number);
    sql.bindValue(":name", name);
    sql.bindValue(":firstp", firstp);
    sql.bindValue(":nextp", nextp);

    bool addIF = sql.exec();
    if(addIF)
    {
        qDebug() << "修改成功！";
        mainpage::on_umaction_triggered();
    }
    else
    {
        qDebug() << "修改失败!";
    }
}

void mainpage::setgoodsTableInfo()
{
    // 设置表头
    this->dataTableModel->setHorizontalHeaderItem(0, new QStandardItem("商品id"));
    this->dataTableModel->setHorizontalHeaderItem(1, new QStandardItem("商品名称"));
    this->dataTableModel->setHorizontalHeaderItem(2, new QStandardItem("商品个数"));
    this->dataTableModel->setHorizontalHeaderItem(3, new QStandardItem("商品供应价格"));
    this->dataTableModel->setHorizontalHeaderItem(4, new QStandardItem("商品售价"));
    this->dataTableModel->setHorizontalHeaderItem(5, new QStandardItem("供应商名称"));


    // 设置列宽
    ui->shopTable->setColumnWidth(0, 200);
    ui->shopTable->setColumnWidth(1, 200);
    ui->shopTable->setColumnWidth(2, 200);
    ui->shopTable->setColumnWidth(3, 200);
    ui->shopTable->setColumnWidth(4, 200);
    ui->shopTable->setColumnWidth(5, 500);



    // 设置表格只读属性
    ui->shopTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // 最后将设计化的表格，装载在表格上
    ui->shopTable->setModel(this->dataTableModel);
}


// 上方工具栏的商品信息
void mainpage::on_actionxinxi_triggered()
{
    this->dataTableModel->clear();
    // 切换堆栈窗口下标到2
    ui->stackedWidget->setCurrentIndex(2);

    // 点击商品信息后，需要商品信息的数据库加载出来

    qDebug() << "已进入商品信息界面";
    QSqlQuery sql;
    sql.prepare("select * from suply_goods_v");
    sql.exec();

    this->setgoodsTableInfo();

    int row = 0;        // 定义变量row表示表格行数


    while (sql.next())
    {
        this->dataTableModel->setItem(row, 0, new QStandardItem(sql.value("goods_id").toString()));
        this->dataTableModel->setItem(row, 1, new QStandardItem(sql.value("goods_name").toString()));
        this->dataTableModel->setItem(row, 2, new QStandardItem(sql.value("goods_number").toString()));
        this->dataTableModel->setItem(row, 3, new QStandardItem(sql.value("market_price").toString()));
        this->dataTableModel->setItem(row, 4, new QStandardItem(sql.value("shop_price").toString()));
        this->dataTableModel->setItem(row, 5, new QStandardItem(sql.value("supplier_name").toString()));
        row++;
    }
    sql.clear();

}


//查询


void mainpage::on_pushButton2_search_clicked()
{
    // 查的功能
    QString id = ui->lineEdit2_ID->text();
    QString name = ui->lineEdit2_Gname->text();
    if(id == "" && name == "")
    {
        // 若id与name框为空，则默认为刷新商品
        mainpage::on_actionxinxi_triggered();
    }
    else
    {
        QSqlQuery sql;
        sql.prepare("select * from suply_goods_v where goods_id =:id1 AND goods_name =:name1");
        sql.bindValue(":name1", name);
        sql.bindValue(":id1", id);
        qDebug() << id;
        qDebug() << name;
        bool addIF = sql.exec();
        if(addIF)
        {
            qDebug() << "查找成功！";
//          QStringList newRowData;
            int row = 0;
            this->dataTableModel->clear();
            this->setgoodsTableInfo();

//                newRowData << sql.value("goods_id").toString() << sql.value("goods_name").toString() << sql.value("goods_number").toString()
//                           << sql.value("market_price").toString() << sql.value("shop_price").toString() << sql.value("supplier_name").toString();
//                qDebug() << "22222222";
            // 执行sql操作时候，数据指针是停留在数据之前的，因此，我们需要移动一下指针
            while(sql.next())
            {
                this->dataTableModel->setItem(row, 0, new QStandardItem(sql.value("goods_id").toString()));
                this->dataTableModel->setItem(row, 1, new QStandardItem(sql.value("goods_name").toString()));
                this->dataTableModel->setItem(row, 2, new QStandardItem(sql.value("goods_number").toString()));
                this->dataTableModel->setItem(row, 3, new QStandardItem(sql.value("market_price").toString()));
                this->dataTableModel->setItem(row, 4, new QStandardItem(sql.value("shop_price").toString()));
                this->dataTableModel->setItem(row, 5, new QStandardItem(sql.value("supplier_name").toString()));
            }
            sql.clear();
        }
        else
        {
            qDebug() << "查找失败!";
        }
    }
}

// 修改售价按钮
void mainpage::on_pushButton2_modify_clicked()
{
    QString id = ui->lineEdit2_ID->text();
    QString name = ui->lineEdit2_Gname->text();
    QString price = ui->lineEdit2_Gprice->text();

    if(id == "" || name == "" || price == "")
    {
        qDebug() << "某个输入框输入为空";
    }
    else
    {
        QSqlQuery sql;
        sql.prepare("update goods set shop_price =:price where goods_id =:id AND goods_name =:name");
        sql.bindValue(":name", name);
        sql.bindValue(":id", id);
        sql.bindValue(":price", price);
        qDebug() << id;
        qDebug() << name;
        bool addIF = sql.exec();

        if (addIF)
        {
            qDebug() << "修改成功！";
            this->on_pushButton2_search_clicked();
        }
        else
        {
            qDebug() << "修改失败!";
        }
    }
}

void mainpage::on_actionjinhuo_triggered()
{
    // 切换堆栈窗口下标到3
    ui->stackedWidget->setCurrentIndex(3);
}

bool mainpage::ifSupplier()
{
    QString supplier_id = ui->lineEdit3_suplierID->text();
    QString supplier_name = ui->lineEdit3_suplierName->text();
    QString supplier_desc = ui->lineEdit3_suplierDesc->text();

    QSqlQuery sql;
    sql.prepare("select * from supplier where supplier_id =:supplier_id and supplier_name =:supplier_name and supplier_desc =:supplier_desc");
    sql.bindValue(":supplier_id", supplier_id);
    sql.bindValue(":supplier_name", supplier_name);
    sql.bindValue(":supplier_desc", supplier_desc);


    if(sql.exec())
        qDebug() << "执行成功";
    else
        qDebug() << "执行失败";

    if (supplier_id == sql.value("supplier_id").toString())
    {
        qDebug() << "匹配成功";
        return true;
    }
    else
    {
        qDebug() << "匹配失败";
        return false;
    }
    return true;
}

void mainpage::insertSuplier_manage_v()
{
    QString supplier_id = ui->lineEdit3_suplierID->text();
    QString supplier_name = ui->lineEdit3_suplierName->text();
    QString supplier_desc = ui->lineEdit3_suplierDesc->text();

    QString goods_id = ui->lineEdit3_goodsID->text();
    QString goods_name = ui->lineEdit3_goodsName->text();
    QString goods_number = ui->lineEdit3_goodsNum->text();

    QString market_price = ui->lineEdit3_marketPrice->text();
    QString shop_price = ui->lineEdit3_shopPrice->text();
    QString goods_desc = ui->lineEdit3_goodsDesc->text();



    QSqlQuery sql;
    sql.prepare("INSERT INTO splier_manage_v(supplier_id, supplier_name, supplier_desc, goods_id, goods_name, goods_number, market_price, shop_price, goods_desc) VALUES(:supplier_id, :supplier_name, :supplier_desc, :goods_id, :goods_name, :goods_number, :market_price, :shop_price, :goods_desc)");
    sql.bindValue(":supplier_id", supplier_id);
    sql.bindValue(":supplier_name", supplier_name);
    sql.bindValue(":supplier_desc", supplier_desc);

    sql.bindValue(":goods_id", goods_id);
    sql.bindValue(":goods_name", goods_name);
    sql.bindValue(":goods_number", goods_number);

    sql.bindValue(":market_price", market_price);
    sql.bindValue(":shop_price", shop_price);
    sql.bindValue(":goods_desc", goods_desc);

    bool insertIF = sql.exec();
    if(insertIF)
    {
        qDebug() << "插入成功！";

    }
    else
    {
        qDebug() << "插入失败=-=！";
    }
}


void mainpage::on_pushButton3_submit_clicked()
{
    // 获取
//    QString supplier_id = ui->lineEdit3_suplierID->text();
//    QString supplier_name = ui->lineEdit3_suplierName->text();
//    QString supplier_desc = ui->lineEdit3_suplierDesc->text();

//    QSqlQuery sql;
//    sql.prepare("select * from supplier where supplier_id =:supplier_id and supplier_name =:supplier_name and supplier_desc =:supplier_desc");
//    sql.bindValue(":supplier_id", supplier_id);
//    sql.bindValue(":supplier_name", supplier_name);
//    sql.bindValue(":supplier_desc", supplier_desc);
    bool supplierIF = this->mainpage::ifSupplier();
    if(supplierIF)
    {
        qDebug() << "该供应商已存在";
    }
    else
    {
        qDebug() << "无该供应商";
        this->mainpage::insertSuplier_manage_v();
    }
}
