#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QMainWindow>
#include <QStandardItem>
#include <datebase.h>

namespace Ui {
class mainpage;
}

class mainpage : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainpage(QWidget *parent = nullptr);
    ~mainpage();

    // 连接数据库的对象
    Database mydatabase;

    // 设置用户信息表格模式
    void setuinfoTableInfo();

    //设置商品表格信息
    void setgoodsTableInfo();

    // 获取表格信息
    //void getDatabaseInfo();

    // 表格组件模式
    QStandardItemModel* dataTableModel;
private slots:
    // 用户管理
    void on_umaction_triggered();

    // 修改密码
    void on_actionmima_triggered();

    // 重新登录
    void on_actiondenglu_triggered();

    // 商品管理信息
    void on_actionxinxi_triggered();

//    // 库存管理信息
//    void on_actionkucun_triggered();

    // 进货管理
    void on_actionjinhuo_triggered();

//    // 商品结账
//    void on_actionjiezhang_triggered();

//    // 商品统计
//    void on_actiontongji_triggered();

//    // 会员信息维护
//    void on_actionxinxi_2_triggered();

//    // 查询会员信息
//    void on_actionchaxun_triggered();

    // 判断供应商是否存在
    bool ifSupplier();

    void insertSuplier_manage_v();

    // stackedWidget中下标为1的界面这种的“修改”按钮
    void on_pushButton1_submit_clicked();


    void on_pushButton2_search_clicked();

    void on_pushButton2_modify_clicked();

    void on_pushButton3_submit_clicked();

private:
    Ui::mainpage *ui;
};

#endif // MAINPAGE_H
