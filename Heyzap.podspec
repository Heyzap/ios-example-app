Pod::Spec.new do |s|
  s.name         = "Heyzap Ads SDK"
  s.version      = "6.2.2"
  s.summary      = "Advertising SDK for mobile games."
  s.homepage     = "http://developers.heyzap.com/docs"
  s.license = { :type => 'Commercial', :text => 'See http://www.heyzap.com/legal/terms' }
  s.author       = { "Heyzap" => "integration@heyzap.com" }
  s.social_media_url = 'https://twitter.com/heyzap'
  s.source       = { :git => "https://github.com/Heyzap/Heyzap-Ads-SDK.git", :tag => "6.2.0" }

  s.platform     = :ios
  s.requires_arc = true

  s.vendored_frameworks = 'HeyzapAds.framework'
  s.source_files = 'Heyzap.framework/Headers/*.{h}'

  s.frameworks = 'QuartzCore', 'CoreGraphics', 'CoreTelephony'
  s.weak_frameworks = 'StoreKit','AdSupport'
  
end