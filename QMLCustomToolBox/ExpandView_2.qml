import QtQuick 2.0
import QtQuick.Layouts 1.3

Column {
    id : root
    property bool mExpand: true
    property alias titleText: titleText.text
    property alias titleColor: titleRoot.color
    property alias titleSize: titleText.font.pixelSize
    property alias mExpandArea: canExpand.data
    property int pandHeight: 300

    width : parent.width
    spacing: 0
    Rectangle {
        width: root.width
        id : titleRoot
        height : 30
        color : "gray"
        Text {
            width: parent.width
            height:parent.height
            verticalAlignment: Text.AlignVCenter
            id: titleText
            text: qsTr("text")
            font.pixelSize: 24
        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                mExpand = !mExpand
            }
        }
    }
    Rectangle {
        id : canExpand
        visible: true
        width: parent.width
        height: pandHeight
    }

    NumberAnimation{
        id :ani1
        target: canExpand
        property: "height"
        duration: 200
        from : mExpand ? canExpand.height : 0
        to : mExpand ? 0 : pandHeight
        easing.type: mExpand? Easing.InQuart : Easing.OutQuart
    }
    onMExpandChanged: {
        ani1.start()
    }
}
