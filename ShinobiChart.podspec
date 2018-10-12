Pod::Spec.new do |s|
  s.name             = "ShinobiChart"
  s.version          = "2.10.1"
  s.summary          = "This is Shinobi Chart for iOS"
  s.homepage         = "https://github.com/sinbadflyce/ShinobiCharts-Trial"
  s.license          = 'Apache License, Version 2.0'
  s.author           = { "ShinobiControls" => "info@shinobicontrols.com" }
  s.source           = { :git => "https://github.com/sinbadflyce/ShinobiCharts-Trial.git", :tag => s.version.to_s }
  s.social_media_url = 'https://twitter.com/shinobicontrols'
  s.platform         = :ios, '8.0'
  s.requires_arc     = true
  s.ios.vendored_frameworks = 'ShinobiCharts.framework'
  s.frameworks = 'ShinobiCharts'
  s.xcconfig     = { 'FRAMEWORK_SEARCH_PATHS' => '"$(PROJECT_DIR)/../"' }
end