#ifndef EDITOR_H
#define EDITOR_H

#include <QMainWindow>
#include <QFileSystemModel>

#include "GLEditorWidget.hpp"
#include "SceneGraphWidget.hpp"
#include "TransformWidget.hpp"
#include "InspectorWidget.hpp"

namespace Ui {
class Editor;
}

class Editor final : public QMainWindow {
    Q_OBJECT

public:
    explicit Editor(QWidget *parent = 0);
    ~Editor();

private:
    /**********************************************************************************************
     *  GUI Setup
     *********************************************************************************************/
    void init();
    void setupWidgets();
    void setupToolbar();
    void setProjectPath(QString dir);
    void loadFonts();

    void recursive(unsigned int idx, SceneGameObject* parent);

private slots:
    /**********************************************************************************************
     *  File Menu
     *********************************************************************************************/
    void on_newProject_triggered();


    /**********************************************************************************************
     *  View Menu
     *********************************************************************************************/
    void on_toggleView_Project_triggered();
    void on_toggleView_Inspector_triggered();
    void on_toggleView_Console_triggered();
    void on_toggleView_SceneGraph_triggered();


    /**********************************************************************************************
     *  Project Tree
     *********************************************************************************************/
    void on_treeView_clicked(const QModelIndex &index);


    /**********************************************************************************************
     * Toolbar Actions
     *********************************************************************************************/
    void on_actionWireframe_triggered(bool checked);
    void on_actionAdd_GameObject_triggered();

private slots:
    void onGameObjectSelected(QTreeWidgetItem *item, int column);

private:
    Ui::Editor          *ui;

    GLEditorWidget      *glTarget;
    SceneGraphWidget    *sceneGraph;
    TransformWidget     *transformWidget;
    InspectorWidget     *inspector;
    QFileSystemModel    *folderModel, *fileModel;
};

#endif // EDITOR_H
