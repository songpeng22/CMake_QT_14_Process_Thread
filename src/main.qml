import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.2
import QtQuick.Controls.Material 2.0
//import QtQuick.Controls.Universal 2.0
import QtQuick.Dialogs 1.1

Window {
    id:root
	objectName: "objWindow1"
    visible: true
    width: 600
    height: 400
    title: qsTr("Hello World")

    Rectangle{
        id:idRect1
        objectName : "objRect1"
        color: "teal"
        height: idButton1.height
        anchors.left : parent.left
        anchors.right : parent.right

        Button {
            id: idButton1
            objectName: "objButton1"
            x: 0
            y: 0
            width: 173
            height: 88
            text: qsTr("txtButton1")
        }
    }
    Rectangle{
        id:idRect2
        objectName : "objRect2"
        color: "plum"
        height:parent.height * 2 / 3
        anchors.left : parent.left
        anchors.right : parent.right
        anchors.top:idRect1.bottom

    }
}
