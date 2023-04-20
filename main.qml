import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import FluentUI

FluWindow {
    id:app
    width: 640
    height: 480

    FluAppBar{
        id:appbar
        width: parent.width
        title: "Hello World"
    }

    FluButton{
        id:btn
        x: 50; y: 50
        width: 100
        hoverColor: "cyan"
        normalColor: "#5B92DC"

        Text {
            id: enterButton
            color: "white"
            text: qsTr("ENTER")
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.centerIn: parent
        }


    }

}
