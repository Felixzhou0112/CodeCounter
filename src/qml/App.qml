import QtQuick
import QtQuick.Window
import QtQuick.Controls
import FluentUI

Window {
    id:app
    color: "#00000000"
    Component.onCompleted: {
        FluApp.init(app)
        FluTheme.frameless = ("windows" === Qt.platform.os)
        FluTheme.dark = false
        FluApp.routes = {
//            "/":"qrc:/page/MainPage.qml",
            "/codeCounter":"qrc:/qml/page/CodeCounter.qml",
        }
        FluApp.initialRoute = "/codeCounter"
        FluApp.run()
    }

}
