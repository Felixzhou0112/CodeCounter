import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs
import FluentUI
import Counter

FluWindow {
    id: app
    width: 640
    height: 480

    title: "CodeCounter"

    FluAppBar {
        id: appbar
        width: parent.width
        title: "CodeCounter"
    }

    CodeCounter {
        id: code_counter
    }

    FluButton {
        id: choose_btn
        x: 500
        y: 50
        width: 100
        hoverColor: "cyan"
        normalColor: "#5B92DC"

        Text {
            id: choose_btn_txt
            color: "white"
            text: qsTr("Choose")
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.centerIn: parent
        }

        onClicked: {
            file_dialog.visible = true
        }

        FileDialog {
            id: file_dialog
            title: "Select file(s)"
            fileMode: file_dialog.OpenFiles  // TODO: 无法同时选择文件夹
            onAccepted: {
                file_dialog.selectedFiles.forEach(function(file) {
                    console.log("Selected file(s): " + file)
                })
            }
        }

    }

    FluButton {
        id: caculate_btn
        x: 500
        y: 300
        width: 100
        hoverColor: "cyan"
        normalColor: "#5B92DC"

        Text {
            id: caculate_btn_txt
            color: "white"
            text: qsTr("Caculate")
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.centerIn: parent
        }

        onClicked: {
            file_dialog.selectedFiles.forEach(caculate)
        }
    }


    function caculate(url) {
        var qurl = Qt.resolvedUrl(url)
        code_counter.calculateFileLines(qurl)
    }

    function choose_files() {

    }
}
