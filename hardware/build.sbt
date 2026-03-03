// hardware/build.sbt

// Версия Scala, на которой работает Chisel 6.0
scalaVersion := "2.13.12"

// Название вашего проекта
name := "dlinear-asic"
version := "0.1.0"

// Основные зависимости: Chisel и тестирование
libraryDependencies ++= Seq(
  "org.chipsalliance" %% "chisel" % "6.0.0",
  // chiseltest для быстрой отладки внутри Scala (без Verilator)
  "edu.berkeley.cs" %% "chiseltest" % "6.0.0" % "test"
)

// Настройки компилятора (плагин для обработки @chiselName и макросов)
addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % "6.0.0" cross CrossVersion.full)

// Опции Scala для корректной работы макросов Chisel
scalacOptions ++= Seq(
  "-language:reflectiveCalls",
  "-deprecation",
  "-feature",
  "-Xcheckinit",
  "-P:chiselplugin:genBundleElements"
)

