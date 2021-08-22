import QtQuick 2.0
import QtQuick.Window 2.3
import QtQuick.Controls 2.13
import QtQuick.Layouts 1.3
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    ScrollView {
        id :sv
        anchors.fill: parent
        Column{
            id : cc
            width : sv.width
            ExpandView_2 {
                id : e2
                pandHeight: 400
                mExpandArea: [
                    Rectangle{
                        color:"lightpink"
                        height : parent.height
                        width: parent.width
                    }
                ]
            }
            ExpandView_2 {
                pandHeight : 600
                mExpandArea: [
                    Rectangle{
                        color:"lightpink"
                        width: parent.width
                        height : parent.height
                    }
                ]
            }
        }
    }
}
