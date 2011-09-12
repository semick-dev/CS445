package com.ts.importing.virtualData.required
{
	import com.ts.data.model.DataIndex;
	import com.ts.data.model.DataProxy;
	import com.ts.importing.configuration.model.enumerations.ExternalImportDataName;
	import com.ts.importing.deriveSystem.model.ImportDataIndex;
	import com.ts.importing.virtualData.AbstractVirtualDataFactory;
	import com.ts.presentation.model.map.SystemProxy;
	
	public class DetectorVFactory extends AbstractVirtualDataFactory
	{
		public static const NAME:String 	= "detector";
		public const REQUIREMENTS:Array 	= [ ExternalImportDataName.LDP_DETECTOR ];
		
		public function DetectorVFactory()
		{
			super( NAME, REQUIREMENTS );
		}
		
		override public function deriveData( dataIndex:DataIndex, importIndex:ImportDataIndex, system:SystemProxy ):void
		{
			var detectorData:Array = importIndex.getDataAtName( ExternalImportDataName.LDP_DETECTOR );
			for each( var dataProxy:DataProxy in detectorData )
			{
				dataIndex.indexDataProxy( dataProxy );
			}
		}
	}
}